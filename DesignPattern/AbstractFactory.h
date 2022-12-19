//
// Created by zst on 2022/12/10.
// ���󹤳�ģʽ������������ˮ��->�������������->������Ʒ
// ��ˮ�߰���������/ʪ����/�ɻ�������/�к������������������Ԥ����ʹ��
//

#ifndef DESIGNP_ABSTRACTFACTORY_H
#define DESIGNP_ABSTRACTFACTORY_H

#include <string>

/**
 * ��������ˮ�ߣ�����1
 */
class DryPipeLine {
public:
    virtual ~DryPipeLine() {};

    // �������������
    virtual std::string dry_process() const = 0;
};

class DryPreProcess : public DryPipeLine {
public:
    std::string dry_process() const override {
        return "������������һ��Ԥ�������";
    }
};

class DryPackage : public DryPipeLine {
public:
    std::string dry_process() const override {
        return "���������������������";
    }
};

/**
 * ʪ����������ˮ�ߣ�����2
 */
class WetPipeLine {
public:
    virtual ~WetPipeLine() {};

    virtual std::string wet_process() const = 0;
};

class WetPreProcess : public WetPipeLine {
public:
    std::string wet_process() const override {
        return "ʪ����������һ����ˮ���";
    }
};

class WetPackage : public WetPipeLine {
public:
    std::string wet_process() const override {
        return "ʪ��������������������";
    }
};

/**
 * �ɻ�������������
 */
class RecPipeLine {
public:
    virtual ~RecPipeLine() {};

    virtual std::string rec_process() const = 0;
};

class RecProProcess : public RecPipeLine {
public:
    std::string rec_process() const override {
        return "�ɻ�������������һ��Ԥ�������";
    }
};

class RecPackage : public RecPipeLine {
public:
    std::string rec_process() const override {
        return "�ɻ����������������������";
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
        return "�к�����������һ��Ԥ�������";
    }
};

class HarPackage : public HarPipeLine {
public:
    std::string harm_process() const override {
        return "�к��������������������";
    }
};

class AbstractFactory {
public:
    virtual DryPipeLine* CreateDryPipeLine() const = 0;

    virtual WetPipeLine* CreateWetPipeLine() const = 0;

    virtual RecPipeLine* CreateRecPipeLine() const = 0;

    virtual HarPipeLine* CreateHarPipeLine() const = 0;
};

class ConcreteProProcess : public AbstractFactory {
public:
    DryPipeLine* CreateDryPipeLine() const override {
        return new DryPreProcess();
    }

    WetPipeLine* CreateWetPipeLine() const override {
        return new WetPreProcess();
    }

    RecPipeLine* CreateRecPipeLine() const override {
        return new RecProProcess();
    }

    HarPipeLine* CreateHarPipeLine() const override {
        return new HarProcess();
    }
};

class ConcretePackage : public AbstractFactory {
public:
    DryPipeLine* CreateDryPipeLine() const override {
        return new DryPackage();
    }

    WetPipeLine* CreateWetPipeLine() const override {
        return new WetPackage();
    }

    RecPipeLine* CreateRecPipeLine() const override {
        return new RecPackage();
    }

    HarPipeLine* CreateHarPipeLine() const override {
        return new HarPackage();
    }
};

#endif //DESIGNP_ABSTRACTFACTORY_H
