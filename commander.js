let triggered = false;

program
	.version('0.1', '-v, --version')
	.usage('[options]')
	.command('quiz')
	.action(() => {
		triggered = true;
	});

program.parse(process.argv);

if(!triggered) {
	inquirer.prompt([{
		type: 'list',
		name: 'menu',
		message: '로또 프로그램 입니다. 메뉴를 선택 해 주세요',
		choices: ['실전 로또', '연습 로또'],
	}])
	.then((answers) => {
		console.log(chalk.green(answers.menu) + "를 선택하셨습니다.");
		selected(answers.menu);
	})
}