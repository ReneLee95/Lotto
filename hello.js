const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function sleep(num4) {
    let count3 = 0;
    for(let i =0; i<num4; i++) {
        count3++;
    }
}


var Lotto = [];
var RLotto = [];

let onecount = 0;
let twocount = 0;

function pushLotto(num) {
    Lotto.push(num);
}

function pushRLotto(num3) {
    RLotto.push(num3);
}

function checkNumber(checknumber,n1) {
    if(checknumber==6) return 1;
    else {
        for(let i =n1; i<7; i++) {
            if(i<6) {
                for(let j = i+1; j<7; j++) {
                    if(Lotto[i] == Lotto[j]) {
                        let x = Math.floor(Math.random()*45)+1;
                        Lotto[i] = x;
                        n1 = i;
                        return checkNumber(checknumber+1,n1);
                    }
                }
            }
        }
    }
}

function checkNumber2(checknumber2,n) {
    if(checknumber2==6) return 1;
    else {
        for(let i =n; i<7; i++) {
            if(i<6) {
                for(let j = i+1; j<7; j++) {
                    if(RLotto[i] == RLotto[j]) {
                        let y = Math.floor(Math.random()*45)+1;
                        RLotto[i] = y;
                        n = i;
                        return checkNumber2(checknumber2+1,n);
                    }
                }
            }
        }
    }
}

function RandomLotto() {
    for(let i = 0; i<7; i++) {
        pushRLotto(Math.floor(Math.random() * 45) +1);
    }

    checkNumber2(0,0);

    for(let i =0; i<7; i++) {
        if(i == 6) {
            console.log("(보너스)로또의 "+ (i+1) +"번째 당첨번호는" + RLotto[i] + " 입니다.");
        }
        else {
            console.log("로또의 "+ (i+1) +"번째 당첨번호는" + RLotto[i] + " 입니다.");
        }
    }
}

function place() {

    console.log("\n\n");
    console.log("당신의 등수는..");

    for(let i =0; i <6; i++) {
        if(i<6) {
            for(let j =0; j<6; j++) {
                if(Lotto[i] == RLotto[j]) {
                    onecount++;
                }
            }
        }
    }
    if (Lotto[6] == RLotto[6]) twocount ++;
    
    if(onecount ==6) {
        console.log("\n\n");
        console.log("■             ■■■■■■");
        console.log("■             ■");
        console.log("■             ■■■■■■");
        console.log("■");
        console.log("■          ■■■■■■■■");
        console.log("■");
        console.log("■                ■■");
        console.log("■                ■■");
    }
    else if (onecount == 5 && twocount == 1) {
        console.log("■■■■■■        ■■■■■■");
        console.log("          ■        ■");
        console.log("          ■        ■■■■■■");
        console.log("          ■");
        console.log("■■■■■■     ■■■■■■■■■");
        console.log("■");
        console.log("■                      ■■");
        console.log("■■■■■■            ■■");
    }
    else if (onecount == 5 && twocount == 0) {
        console.log("■■■■■■        ■■■■■■");
        console.log("          ■        ■");
        console.log("          ■        ■■■■■■");
        console.log("          ■");
        console.log("■■■■■■     ■■■■■■■■■");
        console.log("          ■");
        console.log("          ■            ■■");
        console.log("■■■■■■            ■■");
    }
    else if ((onecount == 3 && twocount == 1) && (onecount == 4 && twocount == 0)) {
        console.log("    ■■        ■■■■■■");
        console.log("   ■ ■        ■");
        console.log("  ■  ■        ■■■■■■");
        console.log(" ■   ■");
        console.log(" ■■■■■■  ■■■■■■■");
        console.log("     ■");
        console.log("     ■             ■■");
        console.log("     ■             ■■");
    }
    else if (onecount == 5 && twocount == 1) {
        console.log("■■■■■■        ■■■■■■");
        console.log("■                  ■");
        console.log("■                  ■■■■■■");
        console.log("■");
        console.log("■■■■■■     ■■■■■■■■■");
        console.log("          ■");
        console.log("          ■            ■■");
        console.log("■■■■■■            ■■");
    }
    else {
        console.log("■■■■■■■   ■     ");
        console.log("    ■      ■   ■");
        console.log("    ■      ■   ■■■■■■");
        console.log("    ■  ■  ■   ■");
        console.log("        ■       ■");
        console.log("■■■■■■■■");
        console.log("                ■■");
        console.log("                ■■");
    }
}

function startLotto() {
    for(let i = 0; i<7; i++) {
        pushLotto(Math.floor(Math.random() * 45) +1);
    }

    checkNumber(0,0);

    for(let i =0; i<7; i++) {
        if(i == 6) {
            console.log("(보너스)당신의 "+ (i+1) +"번째 번호는" + Lotto[i] + " 입니다.");
        }
        else {
            console.log("당신의 "+ (i+1) +"번째 번호는" + Lotto[i] + " 입니다.");
        }
    }
    console.log("\n\n");
    console.log("잠시만 기다려 주세요.");

    console.log("\n\n");

    sleep(5000000000);

    RandomLotto();

    console.log("\n\n");
    console.log("당첨 발표하겠습니다 잠시만 기다려 주십시오.")
    sleep(5000000000);

    place();
    
}

function main() {

    console.log("\n");
    console.log("■■■■■■■■■■■■■■■■■■■■■");
    console.log("■ 1■ 2■ 3■ 4■ 5■ 6■ 7■ 8■ 9■10■")
    console.log("■■■■■■■■■■■■■■■■■■■■■");
    console.log("■11■12■13■14■15■16■17■18■19■20■")
    console.log("■■■■■■■■■■■■■■■■■■■■■");
    console.log("■21■22■23■24■25■26■27■28■29■30■")
    console.log("■■■■■■■■■■■■■■■■■■■■■");
    console.log("■31■32■33■34■35■36■37■38■39■40■")
    console.log("■■■■■■■■■■■■■■■■■■■■■");
    console.log("■41■42■43■44■45■")
    console.log("■■■■■■■■■■■");
    console.log("\n");

    var answer;
    console.log("안녕하세요 로또 프로그램 입니다.");
    console.log("\n");
    console.log("1. 게임 시작, 2. 나가기")
    console.log("\n");
    rl.question('메뉴를 골라주세요.(숫자로 입력)', answer => {
        console.log(`${answer} 를(을) 선택하셨습니다.\n`);
        if(answer == 1) {
            console.log("지금부터 6개의 일반 번호와, 1개의 랜덤한 보너스 번호가 선택이 됩니다..");
            startLotto();
        }
        else if(answer == 2) {
            process.exit();
        }
        else {
            console.log("다시 입력 해 주세요.")
           // rl.prompt();
        }
      
        rl.close();
      });
}

main();