class Weapon {

public:
    Weapon(const std::string& type);
    ~Weapon();

    const std::string& getType() const;
    void setType(const std::string& type);

private:
    std::string _type;

}