module.exports = tiles => {
    const toi = new Array()
    const check = new Array()
    for(const i = 0; i < tiles.length; i++)
        check.push(true)

    for(let i = 0; i < tiles.length; i++) {
        if((tiles[i].type == tiles[i+1].type) && check[i]) {
            if(tiles[i].number == tiles[i+1].number) {
                // 일단 머리 조건은 채움.
                // 코오쯔와 구분해야 함
                if(tiles[i].type == tiles[i+2].type && tiles[i].number == tiles[i+2].number) {
                    // 코오쯔일 경우
                    check[i] = check[i+1] = check[i+2] = false
                    i += 2
                }
                else {
                    // 머리가 맞을 경우
                    toi.push(tiles[i])
                    check[i] = check[i+1] = false
                    i += 1
                }
            }
        } else {
            check[i] = false
        }
    }
    //chitoitsu일 경우 toi의 length = 7, 다른 yaku에는 length = 1
    return toi
}