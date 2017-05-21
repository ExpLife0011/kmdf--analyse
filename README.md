# kmdf
开发环境搭建：
安装win10版本的wdk包，vs2015 pro版本。
kmdfui是界面 界面使用的开源dulib界面库做的，由于界面美观不太好，就直接使用了界面库内的例程的界面稍微修改就直接使用了。目前界面上只做了进程的行为监控的展示。
界面上从驱动取出的数据，目前还没做任何的加工过滤处理，在显示时会有大量的注册表信息干扰，看着很麻烦。
kmdf是驱动代码：驱动代码做了进程的创建，注册表，文件，网络连接等行为的采集，我的想法是把驱动做成一个数据采集器，界面对数据进行加工处理和展示。这样代码的调试会方便很多，修改也方便，驱动是一个独立的模块功能对界面的依赖就很小，通用性更好些。
驱动的安装：
在win7 64位时会有驱动签名验证，大家可以使用wdk自带的签名工具进行签名，目前代码使用的test签名，在使用时需要使用工具内的64Signer开启win7的驱动测试功能，然后重启机器，接着使用driverload加载驱动，后面大家都知道打开界面程序查看数据了。
写这个的初衷是在工作时需要在win7 64位系统上跑一下进程行为，而在网上也没找到符合需求的，就直接写了个，自己也学习下驱动开发，发现和应用层开发还是有差别的，应用的的很多工具类都不能使用，虽说在驱动层可以重写这些工具，但会造成驱动代码很臃肿。暂时先这样了。
代码有不完美的地方，觉得还可以加些功能，大家有什么想法，欢迎加入553539207交流学习。我也是第一次写驱动。有不妥的地方，望大家谅解。
代码以后会受到不定时的更新添加些新功能，界面上的展示做些优化，加些可操作的功能对书据进行过滤。