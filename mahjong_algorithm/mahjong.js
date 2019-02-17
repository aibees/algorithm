/* 
    p = {  // 각 패에 대한 정보
        type: int, //1 : 만수패, 2 : 삭수패, 3 : 통수패, 4 : 사풍패, 5 : 삼원패
        number: int,
        noble: boolean, // 귀족패 영어를 모름
        tsumo: boolean,
        dora: boolean,
        uradora: boolean,
        akadora: boolean,
    }

    input = { // 역 계산을 위한  input 값
        ps: array[p],
        orum: p,
        afterRiichi: int,
        tsumo: boolean, // true: tsumo || false: ron
        riichi: boolean,
        jang: string,
        ja: string,
    }
*/

// 날 수 있는 상태인지도 확인해야 함
// input에 들어온 ps array부터 sort
// 문제는 일발이 


module.exports = input => {
    const yaku = new Array()
    let aka = 0; dora = 0

    input.ps = require('.sort')(input.ps) //sorting됨

    /* 
        리치

        일발

        // 특이상황
            영상개화
            창깡
            해저로월
            하저로어

        // 문전 한정
            평화
            리치
            더블리치
            멘젠쯔모
            치또이쯔
            이페코
            량페코

        // 문전 준한정
            혼일색
            청일색
            찬타
            준찬타
            삼색동순
            일기통관(잇쯔)

        // 문전 비한정
            역패
            탕야오
            또이또이
            삼색동각
            소삼원
            대삼원
            삼깡쯔

        도라
    */
    return yaku
}

