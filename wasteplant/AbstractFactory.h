//
// Created by zst on 2022/12/10.
// 抽象工厂模式，垃圾处理流水线->工厂，处理机器->工厂产品
// 流水线包括干垃圾/湿垃圾/可回收垃圾/有害垃圾，处理机器包括预处理和打包
//

#ifndef DESIGNP_ABSTRACTFACTORY_H
#define DESIGNP_ABSTRACTFACTORY_H

#include <string>

/**
 * 干垃圾流水线，工厂1
 */
class DryPipeLine {
public:
    virtual ~DryPipeLine() {};

    // 干垃圾处理机器
    virtual std::string dry_process() const = 0;
};

class DryPreProcess : public DryPipeLine {
public:
    std::string dry_process() const override {
        return "干垃圾处理步骤一：预处理完成";
    }
};

class DryPackage : public DryPipeLine {
public:
    std::string dry_process() const override {
        return "干垃圾处理步骤二：打包完成";
    }
};

/**
 * 湿垃圾处理流水线，工厂2
 */
class WetPipeLine {
public:
    virtual ~WetPipeLine() {};

    virtual std::string wet_process() const = 0;
};

class WetPreProcess : public WetPipeLine {
public:
    std::string wet_process() const override {
        return "湿垃圾处理步骤一：沥水完成";
    }
};

class WetPackage : public WetPipeLine {
public:
    std::string wet_process() const override {
        return "湿垃圾处理步骤二：发酵完成";
    }
};

/**
 * 可回收垃圾处理工厂
 */
class RecPipeLine {
public:
    virtual ~RecPipeLine() {};

    virtual std::string rec_process() const = 0;
};

class RecProProcess : public RecPipeLine {
public:
    std::string rec_process() const override {
        return "可回收垃圾处理步骤一：预处理完成";
    }
};

class RecPackage : public RecPipeLine {
public:
    std::string rec_process() const override {
        return "可回收垃圾处理步骤二：打包完成";
    }
};

class HarPipeLine {
public:
    virtual ~HarPipeLine() {};

    virtual std::string harm_process() const = 0;
};

class HarProcess : public HarPipeLine {
public:
    std::string harm_process() const override {
        return "有害垃圾处理步骤一：预处理完成";
    }
};

class HarPackage : public HarPipeLine {
public:
    std::string harm_process() const override {
        return "有害垃圾处理步骤二：打包完成";
    }
};

class AbstractFactory {
public:
    virtual DryPipeLine *CreateDryPipeLine() const = 0;

    virtual WetPipeLine *CreateWetPipeLine() const = 0;

    virtual RecPipeLine *CreateRecPipeLine() const = 0;

    virtual HarPipeLine *CreateHarPipeLine() const = 0;
};

class ConcreteProProcess : public AbstractFactory {
public:
    DryPipeLine *CreateDryPipeLine() const override {
        return new DryPreProcess();
    }

    WetPipeLine *CreateWetPipeLine() const override {
        return new WetPreProcess();
    }

    RecPipeLine *CreateRecPipeLine() const override {
        return new RecProProcess();
    }

    HarPipeLine *CreateHarPipeLine() const override {
        return new HarProcess();
    }
};

class ConcretePackage : public AbstractFactory {
public:
    DryPipeLine *CreateDryPipeLine() const override {
        return new DryPackage();
    }

    WetPipeLine *CreateWetPipeLine() const override {
        return new WetPackage();
    }

    RecPipeLine *CreateRecPipeLine() const override {
        return new RecPackage();
    }

    HarPipeLine *CreateHarPipeLine() const override {
        return new HarPackage();
    }
};

#endif //DESIGNP_ABSTRACTFACTORY_H
