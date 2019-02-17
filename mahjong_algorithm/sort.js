// 14개의 패들을 sort해야한다
// 만수패 -> 삭수패 -> 통수패 -> 사풍패(동남서북) -> 삼원패(백발중) 순으로 정리

module.exports = arrays => {
    sorted = arrays.sort(function(a, b) {
        if(a.type != b.type) {
            return a.number - b.number
        }
        return a.type - b.type
    })
    return sorted
}