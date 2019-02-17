module.exports = tiles => {
    const kan = new Array()
    const check = new Array()
    for(const i = 0; i < tiles.length; i++)
        check.push(true)

    for(let i = 0; i < tiles.length; i++) {
        if((tiles[i].type == tiles[i+1].type == tiles[i+2].type == tiles[i+3].type) && check[i]) {
            if(tiles[i].number == tiles[i+1].number == tiles[i+2].number == tiles[i+3].number) {
                //코오쯔 성립. kan array에 identifierTile만 입력
                kan.push(tiles[i])
                //검사된 tile들은 false 처리
                check[i] = check[i+1] = check[i+2] = false
            }
        } else {
            check[i] = false
        }
    }
    return kan
}