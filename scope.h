#ifndef SCOPE_H
#define SCOPE_H

//struct SCOPESETTINGS;

class scope
{
    //struct scopeSettings;
    public:
        scope();
        void closeScope();
        void initializeScope(const struct SCOPESETTINGS&);
        void getScopeData(const char* x, const struct SCOPESETTINGS&);
        //void getScopeData(std::string x);
};

#endif // SCOPE_H
