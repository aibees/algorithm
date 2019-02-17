module.exports = tiles => {
    const shuntsu = require('./shuntsu')(tiles)
    const kotsu = require('./Kotsu')(tiles)
    const kantsu = require('./kantsu')(tiles)
    const mentsu = new Array()
    mentsu.concat(shuntsu)
    mentsu.concat(kotsu)
    mentsu.concat(kantsu)
}