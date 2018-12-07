﻿#include "MainWindow.hpp"
#include <QApplication>

#include "TextDraw.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    auto varDrawPack = std::make_shared<TextDrawPack>();
    TextDraw varTextDraw;

    varDrawPack->pageWidth = 256 ;
    varDrawPack ->pageHeight = 720 ;
    varDrawPack->topMargin = 10 ;
    varDrawPack->bottomMargin = 10 ;
    varDrawPack ->leftMargin = 10 ;
    varDrawPack ->rightMargin = 10 ;
    varDrawPack->titleRawString=QString::fromUtf8(u8R"(序:不是走向成功,就是走向毁灭)");
    varDrawPack->bodyRawString=QString::fromUtf8(u8R"(他的形象一看就十分邪恶，魔气凛然，杀意弥漫。最擅长的事情，就是践踏规则，斩杀名门正道。
方源，乖乖地交出春秋蝉，我给你个痛快！”
    “方老魔，你不要妄图反抗了，今日我们正道各大派联合起来，就是要踏破你的魔窟。这里早已经布下天罗地网，这次你必定身首异处！”
    “方源你个该死的魔头，你为了练成春秋蝉，杀了千万人的性命。你已经犯下了滔天的罪孽，罪无可恕，罄竹难书！”
    “魔头，三百年前你侮辱了我，夺走了我的清白之身，杀光我全家，诛了我的九族。从那刻起，我恨不得吃你肉，喝你的血！今天，我要让你生不如死！！”
    ……
    方源一身残破的碧绿大袍，披头散发，浑身浴血，环第一节：纵身亡魔心仍不悔顾四周。
    山风吹得血袍飘荡，如战旗般嚯嚯作响。

    鲜红的血液，从身上数百道伤口向外涌着。只是站着一会儿，方源脚下已经积了一大滩的血水。

    群敌环伺，早已经没有了生路。

    大局已定，今日必死无疑。

    方源对局势洞若观火，不过即便死亡将临，他仍旧是面不改色，神情平淡。

    他目光幽幽，如古井深潭一般，一如既往的深不见底。

    围攻他的正道群雄，不是堂堂一派之长者尊贵，就是名动四方之少年英豪。此时牢牢包围着方源，有的在咆哮，有的在冷笑，有的双眼眯起闪着警惕的光，有的捂着伤口恐惧地望着。

    他们没有动手，都忌惮着方源的临死反扑。

    就这样紧张地对峙了三个时辰，夕阳西下，落日的余晖将山边的晚霞点燃，一时间绚烂如火。

    一直静如雕塑的方源，慢慢转身。

    群雄顿时一阵骚动，齐齐后退一大步。

    此刻，方源脚下的灰白山石，早已经被鲜血染成第一节：纵身亡魔心仍不悔了暗红。因为失血过多而显得苍白的脸，被晚霞映照着，忽然增添了一份嫣然之光彩。

    看着这青山落日，方源轻声一笑：“青山落日，秋月春风。当真是朝如青丝暮成雪，是非成败转头空。”

    说这话的时候，眼前忽的就浮现出前世地球上的种种。

    他本是地球上的华夏学子，机缘巧合穿越到这方世界。辗转颠簸三百年，纵横世间两百余年，五百多年光阴悠悠，却是晃眼即逝。

    深埋在心底的许多记忆，在此刻鲜活起来，栩栩如生地在眼前回现着。

    “终究是失败了呀。”方源心中叹着，有些感慨，却并不后悔。

    这种结果，他也早有预见。当初选择时，就有了心理准备。

    所谓魔道，就是不修善果，杀人放火。天地不容，举世皆敌，还要纵情纵横。

    “若是刚炼成的春秋蝉有效，来生还是要做邪魔！”这般想着，方源情不自禁放声大笑。

    “老魔，你笑什么？”

    “大家小心，魔头死到临头要反扑了！”

    “快快交出春秋蝉！！”

    群雄逼迫而来，恰在这时，轰的一声，方源悍然自爆。

    ……

    春雨绵绵，悄无声息地滋润着青茅山。

    夜已经深了，丝丝凉风吹拂着细雨。

    青茅山却不黑暗，从山腰至山脚，闪着许多莹莹的微光，好像是披着一条灿烂的光带。

    这些光来源于一座座高脚吊楼，虽称不上万家灯火，却也有数千的规模。

    正是坐落在青茅山的古月山寨，给广袤幽静的山峦增添了一份浓郁的人烟气息。

    古月山寨的最中央，是一座大气辉煌的楼阁。此时正举办着祭祀大典，因此更是灯火通明，光辉绚烂。

    “列祖列宗保佑，希望此次开窍大典中能多多涌现出资质优秀的少年，为家族增添新血和希望！”古月族长中年模样，两鬓微霜，一身素白庄重的祭祀服装，跪在棕黄色的地板上，直着上身，双手合十，紧闭双目诚心祈祷。

    他面对着高高的黑漆台案，在台案有三层，供奉着先祖的牌位。牌位两侧摆着赤铜香炉，香烟袅袅。

    在他的身后，也同样跪着十余人。他们穿着宽大的白色祭服，都是家族中的家老、话事人，执掌着各方面的权柄。

    祈祷了一番后，古月族长率先弯腰，双手平摊，掌心紧紧贴着地板，磕头。额头碰在棕色的地板上，发出轻轻的砰砰声。

    身后的家老们各个表情肃穆，也随着默默效仿。

    一时间，宗族祠堂中尽是额头碰撞地板的轻响。

    大典完毕，众人慢慢地从地板上站起身来，静静地走出庄严的祠堂。

    在走廊中，众家老默默地舒了一口气，气氛为之一松。

    议论声渐渐地起来。

    “时间过的真是太快了，一眨眼，一年就都过去了。”

    “上一届的开窍大典就像是昨天发生的一样，依旧历历在目呢。”

    “明日就是一年一度的开窍大典了，不知道今年会涌现出什么样的家族新血呢？”

    “唉，希望有甲等资质的少年出现。我们古月一族已经有三年没有这样的天才出现了。”

    “不错，白家寨、熊家寨这些年都有天才涌现。尤其是白家的白凝冰，天资真是恐怖。”

    不知是谁，提及到白凝冰这个名字，众家老的脸上不由地浮现出一层忧色。

    此子的资质极端出色，短短两年功夫，就已经修行到三转蛊师。在年轻一辈中，可谓独领风骚。甚至就连老一辈们都感觉到了这位后起之秀的压力。

    假以时日，他必然是白家寨的顶梁柱。至少也是独当一面的强者。没有人怀疑过这一点。

    “不过今年参加开窍大典的少年里，也不是没有希望。”

    “不错，方之一脉出现了一个天才少年。三月能言，四月能走。五岁时就能作诗诵词，聪慧异常，才华横溢。可惜就是父母死的早，现在被其舅父舅母抚养着。”

    “嗯，这是有早智的，而且有大志向。近些年他创作的《将敬酒》、《咏梅》，还有《江城子》我也听说过，真是天才！”

    古月族长最后一个走出宗祖祠堂，慢慢地关上门，便听到走廊中家老们的议论声音。

    顿时就知道，家老们此时议论的是一位叫做古月方源的少年。

    作为一族之长，对于那些优秀而突出的子弟自然会关注。而古月方源就是小辈当中，最为出色耀眼的一位。

    而经验表明，往往从小就过目不忘，或者力气大如成人等等天赋异禀的人，都有优秀的修行资质。

    “若是此子测出甲等资质，好生培养，也未必不能和白凝冰抗衡。就算是乙等资质，日后定也能独当一面，成为古月一族的一面旗帜。不过他这样的早慧，乙等资质的可能性不大，极有可能就是甲等。”这一念生出，古月族长的嘴角不由地微微翘起，浮现出一抹微笑。

    旋即，咳嗽一声，对诸位家老们道：“诸位，时候不早了，为了明日的开窍大殿，今晚请务必好好休息，保养精神。”

    家老们听了这话，都微微一怔。看向彼此的目光中都隐藏了一丝警惕之色。

    族长这话说的含蓄，但大家都深晓其意。

    每年为了争夺这些天才后辈，家老们彼此之间都是争的面红耳赤，头破血流。

    是该好好的养精蓄锐，待到明天，争上那一番。

    尤其是那个古月方源，甲等资质的可能性非常的大。而且他双亲已经亡故，是方之一脉仅剩下的双孤之一。若是能收入自己这一脉中，好好培养，可保自己这一支百年的昌盛不衰！

    “不过，丑话先说在前头。争要堂堂正正的争，不可以动用阴谋手段，损害家族的团结。诸位家老们请牢记在心！”族长语气严肃地关照道。

    “不敢。不敢。”

    “一定牢记在心。”

    “这就告辞了，族长大人请留步。”

    家老们满怀心思，一一散去。

    不久，长长的走廊上就冷清下来。春雨斜风透过窗户吹拂过来，族长轻轻举步，走到窗前。

    顿时，满口都是清新湿润的山间空气，沁人心脾。

    这是阁楼第三层，族长放眼望去，大半个古月山寨都一览无余。

    此刻深夜，寨中大多数人家却还有着灯火，和平时大不相同。

    明天就是开窍大典，关乎着每个人的切身利益。一种兴奋、紧张的氛围，笼罩着族人的心，自然有很多人睡不安稳。

    “这就是家族未来的希望啊。”眼中倒映着点点灯光，族长长叹一声。

    而此时，同样有一对清亮的眸子，静静地看着这些深夜中闪闪的灯光，满怀复杂情怀。

    “古月山寨，这是五百年前？！春秋蝉果真起作用了……”方源眼神幽幽，站在窗户旁，任凭风雨打在身上。

    春秋蝉的作用，就是逆转时光。在十大奇蛊排名中，能名列第七，自然非同小可。

    简而言之，就是重生。

    “利用春秋蝉重生了，回到了五百年前！”方源伸出手，目光定定地看着自己年轻稚嫩的有些苍白的手掌，然后慢慢握紧，用力感受着这份真实。

    耳畔是细雨打在窗扉上发出的微微声响，他缓缓地闭上眼，半晌后才睁开，喟然一叹：“五百年的经历，真像是个梦啊。”

    但他却清楚的知道，这绝不是梦。
)");
    varDrawPack->titleBodySpace = 20 ;
    varTextDraw.layout(varDrawPack);

    auto varImage = varTextDraw.draw(0);

    w.setImage(varImage);
    w.show();

    return a.exec();
}
