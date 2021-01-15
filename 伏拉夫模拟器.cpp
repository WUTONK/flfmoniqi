//！@！@！@！@！@！@！@！@！@！@！@！@！@！@！@！@！@！@！@！@！@！@！@！@！@! @ ! @ ! @ ! @ ! @ !
//                                                                                                                       
//                                     欢迎进入源代码页面！━(*｀∀´*)ノ亻!                                                                                      
//                                                                                                                       
//                                      项目：伏拉夫模拟器                                                                                    
//                                      版本：alpha v.0.0.11                                                                            
//                                      开发者：WUTONG                                                                             
//                                      开始日期：2020-6-13   
//                                      最后编辑日期：2021-1-15
//                                      本页面功能：主页以及游戏逻辑运行                                                                              
//                                                                                                                       
//                                                                                                                       
//                                                                                                                       
//（由于本人的低技术力，main主函数代码将基本承担一切的游戏逻辑以及变量调用操作，暂时无法使用其他.cpp文件）                                                                                
//                                                                                                                       
//                                                                                                                       
//                                                                                                                       
//                                                                                                                       
//                                                                                                                                                                                             
//                                                                                                                       
//                          ps:          此处为注释       源代码在下方     
//                                                                                                                       
//_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+




















#include<iomanip>			//忘了为啥用
#include<ios>					//我也不知道拿来干嘛,但是多加一个没啥坏处
#include <iostream>		//输入输出流
#include <string.h>         //用于字符串功能补全
#include<stdlib.h>			//用于整数和字符串互相转换
#include <time.h>　　　// 定义关于时间的函数
#include <wchar.h>　 　// 宽字符处理及输入／输出
#include <wctype.h>      //别人告诉我要用
#include <string>          //用于string转换和各种变量互相转换，存档会用到
#include <sstream>       //用于使用stringstream字符串
#include <fstream>    //
#include "windows.h"//bzd
#include "conio.h"//用于键盘输入


#define upspace 3
#define leftspace 4



using namespace std;      //定义命名空间，我才懒得写std:,用这个一步解决

void cundang();//用于存档页面的函数
void save();//用于存档功能的示例
void cunsave();//存档
void dusave();//读档
void zhuyemian();//用于主页面的函数
void kaishiyemian();//用于开始页面的函数
void chushizhuyemian();//用于显示初始进入时的页面
void shuxing();//用于调用属性
void shuxinggenggai();//用于玩家游戏中更改属性，例如频道名，团队名等
void xianshishuxing();//用于显示属性
void shuxingjisuan();//用于各种属性的计算，例如播放量，订阅数，收益
void tuandui();//用于团队功能的实现





//全局变量表 (由于限制,目前游戏中需要保存到存档的变量将尽量不使用高精度和浮点变量)

int kafazhemima = 0;//开发者密码变量
int xingshoujiaochengchakan = 3;//输入是否要查看新手教程时用来输入数字的变量
int sex = 3;//玩家性别/save1
int sexyn = 2;//用于检测女玩家性别输入是否正确
int sexyn2 = 2;//用于检测男玩家性别输入是否正确
int homemoney = 4;// 用于存储玩家家庭状况/save2
int money = 0;//用于存储玩家金钱数量（软妹币）/save3
int homemoneyyn = 0;//用于检测玩家是否将家庭富裕程度输入正确
int nationality = 10;//用于存储玩家国籍/save4
int nationalityyn = 0;//用于检测玩家是否将国籍输入正确
int netvideo = 0;//用于存储玩家上传过的视频数量/save5
int youguanyn = 0;//用于存储玩家是否启用油罐/bsave1
int dyyn = 0;//用于存储玩家是否启用抖阴/bsave2
int pilipiliyn = 0;//用于存储玩家是否启用噼哩噼哩/bsave3
int dongguayn = 0;//用于存储玩家是否启用冬瓜视频/bsave4
int aiqiyiyn = 0;//用于检测癌奇亿是否启用/bsave5
int youkuyn = 0;//用于存储玩家是否启用油库/bsave6
int netvideoyn = 3;//检测玩家是否确认启用选择的视频平台
int netvideonet = 9;//检测玩家选择启用哪一个视频平台
int pintaijieshaoyn = 2;//检测玩家是否要查看平台介绍
int pindaonameyn = 3;//检测玩家是否确认频道名
int dingyueshu = 0;//总订阅数/save6
int bofangliang;//用于保存总播放量/save7
int youguanbofang = 0;//用于保存油罐总播放量/bsave10
int dybofang = 0;//用于保存抖阴总播放量/bsave11
int pilipilibofang = 0;//用于保存噼哩噼哩总播放量/bsave12
int dongguabofang = 0;//用于保存冬瓜视频总播放量/bsave13
int aiqiyibofang = 0;//用于保存癌奇亿总播放量/bsave14
int youkubofang = 0;//用于保存油库总播放量/bsave15

int anjian1;//按键检测缓存


char asave[1000];//用于存储基本信息
char bsave[1000];//用于存储频道信息
char adata[1000];//备用
char bdata[1000];//备用

char namedata[3];//为了char[]和string类型互相转换所用







string name;//玩家游戏内姓名/save0
string pindaoname001;//频道初始名
string dudangwen;//读档临时文件储存用
string cundangwen;//存档临时文件储存用
string cundangddx;//用来显示读档数据
string cundangcdx;//用来显示存档数据



stringstream cundangdd;//用于后续读取存档的转换，详情请看注释.cpp
stringstream cundangcd;//用于后续存档的转换存储

int main()//主函数

{

	//chushizhuyemian();//调用主页面函数
	//cundang();//调用存档函数
	zhuyemian();

	return 0;
}
//以下是各种函数的源代码





//此函数为预留位，暂且搁置~

void save(){

	char data[100];

	// 以写模式打开文件
	ofstream outfile;
	outfile.open("save.txt");

	cin.getline(data, 100);//getline的作用是实现存储特殊字符（例如空格）到字符串文件中,

	// 向文件写入用户输入的数据
	outfile << data << endl;

	cout << "Enter your age: ";
	cin >> data;
	cin.ignore();//删除上面的data文件{在缓存区}

	// 再次向文件写入用户输入的数据
	outfile << data << endl;

	// 关闭打开的文件
	outfile.close();

	// 以读模式打开文件
	ifstream infile;//infine意为"在这个文件中"
	infile.open("save.txt");

	cout << "正在加载文件。。。" << endl;
	infile >> data;

	// 在屏幕上写入数据
	cout << data << endl;

	// 再次从文件读取数据，并显示它
	infile >> data;
	cout << data << endl;

	// 关闭打开的文件
	infile.close();

	return;
}

//此函数用于存档页面@！

void cundang()
{

	int cundu = 3;

//label0;//用于后续数字输入错误后的GOTO跳转
	system("cls");//清屏


	cout << "                 欢迎进入存档页面" << endl << endl;
	cout << "                     请选择功能" << endl << endl;
	cout << "                   0.存档    1.读档" << endl;
	cin >> cundu;

	if (cundu == 0)
	{
		cunsave();
		

	

		return;
	}

	system("cls");//清屏

	if (cundu == 1)
		{

		dusave();


		return;

		}

		



	cout << "检测到数字输入异常,可能是输入错误,请重新输入..." << endl;



	return;

}




void cunsave() {
	

	//存档槽还在做
	cout << "                                            请选择存档槽位"<<endl<<endl<<endl<<endl;
	cout << "                                  A.                                               b."<<endl<<endl<<endl;
	cout << "                                           按下对应按键选择";



	system("cls");//清屏
	cout << "正在存档，请等待。。。"<<endl;
	cout << "%0" << endl;

	//////////////////////////////////////////////////////////////////////////////第一次存储
	ofstream outfile;
	outfile.open("asave.txt");

	asave[0] = namedata[1];//玩家姓名
	asave[1] = sex;//玩家性别
	asave[2] = homemoney;//玩家家庭状况
	asave[3] = money;//玩家金钱数
	asave[4] = nationality;//玩家国籍
	asave[5] = netvideo;//玩家上传过的视频总数
	asave[6] = dingyueshu;//总订阅数
	asave[7] = bofangliang;//用于保存总播放量


	bsave[1] = youguanyn;//用于存储玩家是否启用油罐
	bsave[2] = dyyn;//用于存储玩家是否启用抖阴
	bsave[3] = pilipiliyn;//用于存储玩家是否启用噼哩噼哩
	bsave[4] = dongguayn;//用于存储玩家是否启用冬瓜视频
	bsave[5] = aiqiyiyn;//用于检测癌奇亿是否启用
	bsave[6] = youkuyn;//用于存储玩家是否启用油库
	bsave[10] = youguanbofang;//用于保存油罐总播放量
	bsave[11] = dybofang;//用于保存抖阴总播放量
	bsave[12] = pilipilibofang;//用于保存噼哩噼哩总播放量
	bsave[13] = dongguabofang;//用于保存冬瓜视频总播放量
	bsave[14] = aiqiyibofang;//用于保存癌奇亿总播放量
	bsave[15] = youkubofang;//用于保存油库总播放量
	
	///////////////////////////////////////////////////////////////////第一次存储完成


	cout << "%50" << endl;
	cout << "正在写入内存" << endl;

	Sleep(200);


	outfile << asave << endl;//将缓存变量存储到本地存档中
	outfile << bsave << endl;//将缓存变量存储到本地存档中

	/////////////////////////////////////////////////////////////////////下列操作是为了将存档存储到第二个文件，防止误操作
	//outfile.open("asaveold.txt");

	//asave[0] = namedata[1];//玩家姓名
	//asave[1] = sex;//玩家性别
	//asave[2] = homemoney;//玩家家庭状况
	//asave[3] = money;//玩家金钱数
	//asave[4] = nationality;//玩家国籍
	//asave[5] = netvideo;//玩家上传过的视频总数
	//asave[6] = dingyueshu;//总订阅数
	//asave[7] = bofangliang;//用于保存总播放量


	//bsave[1] = youguanyn;//用于存储玩家是否启用油罐
	//bsave[2] = dyyn;//用于存储玩家是否启用抖阴
	//bsave[3] = pilipiliyn;//用于存储玩家是否启用噼哩噼哩
	//bsave[4] = dongguayn;//用于存储玩家是否启用冬瓜视频
	//bsave[5] = aiqiyiyn;//用于检测癌奇亿是否启用
	//bsave[6] = youkuyn;//用于存储玩家是否启用油库
	//bsave[10] = youguanbofang;//用于保存油罐总播放量
	//bsave[11] = dybofang;//用于保存抖阴总播放量
	//bsave[12] = pilipilibofang;//用于保存噼哩噼哩总播放量
	//bsave[13] = dongguabofang;//用于保存冬瓜视频总播放量
	//bsave[14] = aiqiyibofang;//用于保存癌奇亿总播放量
	//bsave[15] = youkubofang;//用于保存油库总播放量

	
	//outfile << asave << endl;//将缓存变量存储到本地存档中
	//outfile << bsave << endl;//将缓存变量存储到本地存档中
	
//////////////////////////////////////////////////////////////////////////////////第二次存储完成

	cout << "%100"<<endl;
	cout << "存档完毕";
	Sleep(500);
	system("cls");//清屏
	outfile.close();//关闭之前打开的文件
}


void dusave() {
	system("cls");//清屏
	cout << "正在读档，请等待。。。"<<endl;

	ifstream infile;//infine意为"在这个文件中"
	infile.open("asave.txt");
	infile >> asave;
	infile >> bsave;

	namedata[1]=asave[0]  ;//玩家姓名
	sex =asave[1] ;//玩家性别
	 homemoney =asave[2];//玩家家庭状况
	money =asave[3] ;//玩家金钱数
	nationality =asave[4] ;//玩家国籍
	netvideo =asave[5] ;//玩家上传过的视频总数
	dingyueshu = asave[6];//总订阅数
	bofangliang = asave[7];//用于保存总播放量


	youguanyn =bsave[1] ;//用于存储玩家是否启用油罐
	dyyn =bsave[2] ;//用于存储玩家是否启用抖阴
	pilipiliyn =bsave[3] ;//用于存储玩家是否启用噼哩噼哩
	dongguayn =bsave[4] ;//用于存储玩家是否启用冬瓜视频
	 aiqiyiyn =bsave[5];//用于检测癌奇亿是否启用
	 youkuyn =bsave[6];//用于存储玩家是否启用油库
	 youguanbofang =bsave[10];//用于保存油罐总播放量
	 dybofang =bsave[11];//用于保存抖阴总播放量
	pilipilibofang =bsave[12] ;//用于保存噼哩噼哩总播放量
	dongguabofang =bsave[13] ;//用于保存冬瓜视频总播放量
	aiqiyibofang =bsave[14] ;//用于保存癌奇亿总播放量
	youkubofang =bsave[15] ;//用于保存油库总播放量


	Sleep(500);

	cout << "读档成功";
	cout << nationality;

	Sleep(500);
	system("cls");//清屏


}

//此函数用于读档功能@！

void cundnag(string s)
{
	int ans;
	stringstream ss(s);//构造字符串流对象，初始化为s
	ss >> ans;//输出流的内容到ans
	return;
}


//该函数用于属性计算功能@！

void shuxingjisuan() {






}

//此函数用于初始主页面@！

void chushizhuyemian() {
	
	string name;
	

	cout << "你好，欢迎使用，目前的版本为a0.0.10" << endl;
    cout << "请输入开发者密码" << endl << endl << endl;
	cout << "请直接输入，然后按回车键" << endl;

	cin >> kafazhemima;//输入开发者密码

	if (kafazhemima == 0)//检测密码是否正确
	{
		cout << "欢迎进入调试_(:з」∠)_，如果发现异常或者是有其他功能的补充和想法，请联系其他开发者" << endl << endl << endl << endl << endl;
	}
	else//输入错误后
	{
		cout << "密码错误，请重新打开程序输入，如果您不是开发者，请退出，本游戏目前为阿尔法内测版,不对外公开" << endl;
		return;
	}

label://用于后续的GOTO跳转

	cout << "                   Hello，欢迎进入游戏，请问是否查看新手教程？" << endl;
	cout << "                                                          请输入数字" << endl << endl << endl << endl << endl << endl;
	cout << "0.查看   1.直接进入游戏" << endl;

	cin >> xingshoujiaochengchakan;

	if (xingshoujiaochengchakan == 0)
	{
		cout << "              此功能没有完成" << endl << endl;
		goto label;//返回到选择是否查看新手教程
	}

	//加载提示
	cout << "           您好，目前已经成功进入游戏" << endl << endl << endl;
	cout << "正在加载内容,请稍等........" << endl;

	//清屏

	system("cls");

	//输入玩家昵称

	
	cout << "     玩家你好，请输入姓名，输入后按回车键（最好是英文，避免使用字符）" << endl << endl;
	cout << " 请输入——————" << endl;
	

	// 向文件写入用户输入的数据
	ofstream outfile;
	outfile.open("save.txt");
	cin.getline(namedata,1);//getline的作用是实现存储特殊字符（例如空格）到字符串文件中,
	
	cin >> name;
	
	name = namedata;
	cout << name;
	cin >> name;
	
	
	

	//检测昵称是否定义成功
	if (name == "0")
	{
		cout << "昵称没有成功输入，请遵循要求输入,并更换昵称" << endl;
	}
	else
	{
		cout << "输入的昵称符合要求，输入成功！，接下来请输入性别" << endl << endl << endl;
	}

	//输入玩家性别

label2://用作选择性别时错误后返回重新选择

	system("cls");//清屏

	//选择玩家性别
	cout << "请选择您的性别" << endl << endl << endl << endl << endl;
	cout << "请按照数字输入" << endl << endl << endl;
	cout << "0.男   1.女" << endl;
	cin >> sex;

	//用于检测女玩家是否输入正确

	if (sex == 1)
	{
		cout << "您的性别为女，是否正确？" << endl << endl;
		cout << "0.不是                   1.是" << endl << endl << endl;
		cin >> sexyn;





		if (sexyn == 0)
		{


			cout << "按任意键到性别选择界面.................";
			system("pause");//用于让玩家输入任意键后继续
			goto label2;

		}

	}
	//用于检测男玩家是否输入正确

	if (sex == 0)
	{

		cout << "您的性别为男，是否正确？" << endl << endl;
		cout << "0.不是                     1.是" << endl << endl << endl;
		cin >> sexyn2;

	}

	if (sexyn2 == 0)
	{


		cout << "按任意键跳转到性别选择界面.................";
		system("pause");//用于让玩家输入任意键后继续
		goto label2;

	}


	//游戏正式开始

label3://

	system("cls");//清屏

	cout << "游戏正式开始，请选择你的基本属性" << endl;
	cout << "请问你的出生是？（请输入数字，然后按回车键）" << endl << endl << endl;
	cout << "0.普通家庭  1.贫穷家庭  2.富裕家庭 " << endl << endl;
	cin >> homemoney;//选择出生
	cout << "您输入的数字为：" << homemoney << endl;
	cout << "           确认出生？" << endl << endl;
	cout << "0.不是   1.是" << endl;
	cin >> homemoneyyn;//选择是否正确输入出生

	if (homemoneyyn != 1)
	{

		goto label3;

	}

label4://用于后续国籍重新输入时的跳转

	system("cls");//清屏

	cout << "请选择您的国籍（国家和地区）";
	cout << "推荐外国国籍，目前版本不要选择中国大陆，会无法正常游玩" << endl << endl << endl;
	cout << "0.中国香港   1.中国台湾  2.中国大陆 3.俄罗斯  4.英国  5.日本  6.韩国  7.澳大利亚  8.美国  9.南非" << endl;
	cin >> nationality;//选择国籍

	cout << "您选择的国籍（国家和地区）为：" << nationality << endl;
	cout << "           确认国籍？" << endl << endl;
	cout << "0.不是   1.是" << endl;
	cin >> nationalityyn;//选择是否确认国籍

	if (nationalityyn != 1)
	{

		goto label4;

	}

	system("cls");//清屏




	cout << endl << endl << endl << endl << endl << endl;//用于将字顶到屏幕中部
	cout << "欢迎开始游戏，在本游戏里，你将扮演伏拉夫，你的工作就是在自媒体平台上恰烂钱,并想方设" << endl;
	cout << "的引起人们的注意，来获得流量。" << endl << endl << endl << endl;
	cout << "即将进入平台选择界面，是否要查看各平台介绍？" << endl << endl;
	cout << "0.否 1.是" << endl << endl;
	cin >> pintaijieshaoyn;

	system("cls");//清屏


	if (pintaijieshaoyn == 1)
	{

		cout << "油罐：第一大平台，用户平均素质中等偏上，对财富密码和甲亢抵御能力一般，收入最高，" << endl;
		cout << "审核最宽松" << endl << endl;

		cout << "抖阴：第二大的平台，用户平均素质较低，对财富密码和甲亢抵御能力较低，收入一般，审" << endl;
		cout << "核宽松" << endl << endl;

		cout << "噼哩噼哩：第三大平台，用户平均素质中等偏上，对财富密码和甲亢抵御能力最强，收入较高，" << endl;
		cout << "审核最严格" << endl << endl;

		cout << "冬瓜视频：第四大平台，用户平均素质低，对财富密码＆甲亢抵御能力最低，收入中等，审核" << endl;
		cout << "一般。" << endl << endl;

		cout << "癌奇亿：第五大平台，用户平均素质低，对财富密码和甲亢抵御能力低，收入低，审核较宽松" << endl << endl;


		cout << "油库：第六大平台，用户平均素质最低，对财富密码＆甲亢抵御能力最低，收入最低，审核宽松" << endl << endl;


		cout << "介绍显示完毕，按任意键继续游戏~";


		system("pause");//用于让玩家输入任意键后继续

	}


label5://用于后续重新选择初始视频平台的跳转

	system("cls");//清屏

	cout << "那么，请先选择你的第一个视频平台" << endl;
	cout << "0.油罐 1.抖阴 2.噼哩噼哩 3.冬瓜视频  4.癌奇亿 5.油库  " << endl;
	cout << "                                                                                  请输入............" << endl << endl;
	cin >> netvideonet;


	//通过玩家输入的序号判定平台

	if (netvideo == 0)//

	{
		youguanyn = 1;
	}

	if (netvideo == 1)

	{
		dyyn = 1;
	}

	if (netvideo == 2)

	{
		pilipiliyn = 1;
	}

	if (netvideo == 3)

	{
		dongguayn = 1;
	}

	if (netvideo == 4)

	{
		aiqiyiyn = 1;
	}

	if (netvideo == 5)

	{
		youkuyn = 1;
	}

	//询问玩家是否选择正确

	cout << "您选择的平台为" << netvideo << endl;
	cout << "是否确认？" << endl << endl << endl;
	cout << "0.是 1.否" << endl;
	cout << "                     请输入........" << endl << endl;
	cin >> netvideoyn;

	if (netvideoyn != 0)
	{
		cout << "按任意键重新跳转到平台选择界面" << endl;
		system("pause");//用于让玩家输入任意键后继续
		goto label5;
	}

	system("cls");//清屏

ladel6://用于后续玩家选择重新起名时的GOTO跳转

	cout << "请给你的频道起一个名字" << endl;
	cout << "请直接输入名字，然后按回车键" << endl;
	cout << "                                    ps:目前不支持每个频道一个名字，但是可以一个团队一个名字" << endl << endl;
	cin >> pindaoname001;
	cout << "" << endl;

	cout << "你的频道名是：" << pindaoname001 << "      是否确认？？" << endl << endl;
	cout << "0.否      1.是" << endl;
	cin >> pindaonameyn;

	if (pindaonameyn != 1)
	{
		cout << "按任意键返回频道名选择页面" << endl;
		system("pause");//用于让玩家输入任意键后继续
		goto ladel6;

	}







	return;
}



//此函数用于定义输出坐标@！此函数作者：bilibili  @阳光下的树叶TREEYEAH

void go(int x, int y)  //光标移动函数，X表示横坐标，Y表示纵坐标。
{
	COORD coord;         //使用头文件自带的坐标结构
	coord.X = (x + leftspace) * 2;            //这里将int类型值传给short,不过程序中涉及的坐标值均不会超过short范围
	coord.Y = y + upspace;
	HANDLE a = GetStdHandle(STD_OUTPUT_HANDLE);  //获得标准输出句柄
	SetConsoleCursorPosition(a, coord);         //以标准输出的句柄为参数设置控制台光标坐标
}

void zhuyemian() {

	go(0,0 ); cout<<"订阅数:"<<dingyueshu;
	




}







// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
