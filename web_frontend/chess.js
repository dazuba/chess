piece_size = 80;
board_size = 80 * 8;

var canvas = document.getElementById("canvas");
canvas.width = board_size;
canvas.height = board_size;
const ctx = canvas.getContext("2d");
var view_color = 0;

const imgs = {
    "board": new Image(),
    "rook0": new Image(),
    "rook1": new Image(),
    "pawn0": new Image(),
    "pawn1": new Image(),
    "knight0": new Image(),
    "knight1": new Image(),
    "bishop0": new Image(),
    "bishop1": new Image(),
    "queen0": new Image(),
    "queen1": new Image(),
    "king0": new Image(),
    "king1": new Image(),
};

for (const [k, v] of Object.entries(imgs)) {
    v.src = '/media/' + k + ".png";
}

function coordsToPoints(x, y) {
    if (view_color == 0) {
        return [x * piece_size, (7 - y) * piece_size];
    } else {
        return [(7 - x) * piece_size, y * piece_size];
    }
}

function pointsToCoords(x, y) {
    if (view_color == 0) {
        return [Math.floor(x / piece_size), 7 - Math.floor(y / piece_size)];
    } else {
        return [7 - Math.floor(x / piece_size), Math.floor(y / piece_size)];
    }
}

selected = {}

function drawField() {
    ctx.drawImage(imgs["board"], 0, 0, board_size, board_size);
}

imgs["board"].onload = () => {
    function drawPiece(name, x, y) {
        var xy = coordsToPoints(x, y);
        ctx.drawImage(imgs[name], xy[0], xy[1], piece_size, piece_size);
    }

    function drawCanEat(x, y) {
        console.log(x, y);
        ctx.fillStyle = "rgba(255, 0, 0, 0.5)";
        ctx.beginPath();
        var xy = coordsToPoints(x, y);
        ctx.ellipse(xy[0] + piece_size / 2, xy[1] + piece_size / 2, piece_size / 2, piece_size / 2, 0, 0, 2 * Math.PI);
        ctx.fill();
    }

    canvas.addEventListener('click', function(event) {
        if (Object.keys(selected).length === 0) {
            var xy = pointsToCoords(event.offsetX, event.offsetY);
            var fromX = xy[0];
            var fromY = xy[1];

            selected["fromX"] = fromX;
            selected["fromY"] = fromY;

            $.ajax({
                url: "handler/valid-moves",
                type: "get",
                data: {
                    "x": fromX,
                    "y": fromY
                },
                success: function(html) {
                    html.forEach(e => {
                        drawCanEat(e["x"], e["y"]);
                    });
                }
            });
        } else {
            var xy = pointsToCoords(event.offsetX, event.offsetY);
            var toX = xy[0];
            var toY = xy[1];

            selected["toX"] = toX;
            selected["toY"] = toY;

            $.ajax({
                url: "handler/make-move",
                type: "post",
                data: selected,
            });

            selected = {};
            updateField();
        }
    });

    function updateField() {
        drawField();
        $.ajax({
            url: "handler/get-board",
            type: "get",
            success: function(html) {
                console.log(html);
                html["pieces"].forEach(e => {
                    drawPiece(e["name"], e["x"], e["y"]);
                });
            }
        });
    }

    updateField();

    $("#btn-toggle-view").click(function() {
        view_color = 1 - view_color;
        updateField();
    });
}
