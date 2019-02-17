module.exports = tiles => {
    const shuntsu = require('./shuntsu')(tiles)
    const kotsu = require('./Kotsu')(tiles)
    const kantsu = require('./kantsu')(tiles)

    const toitsu = require('./toitsu')(tiles)
    const mentsu = new Array()

    mentsu.concat(shuntsu, kotsu, kantsu)
    
    return result = {
        mentsu : mentsu,
        toitsu : toitsu,
        shuntsu : shuntsu,
        kotsu : kotsu,
        kantsu : kantsu
    }
    //  hands가 가지고 있는 정보 : shuntsu, kotsu, kantsu, mentsu, toitsu
}