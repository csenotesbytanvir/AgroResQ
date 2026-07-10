#pragma once

namespace AgroResQ
{
namespace Core
{

class BaseEntity
{
protected:
    int id;

public:
    BaseEntity();
    virtual ~BaseEntity();

    void setId(int id);
    int getId() const;
};

}
}