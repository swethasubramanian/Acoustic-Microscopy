#ifndef SCOPE_H
#define SCOPE_H


class scope
{
    //struct scopeSettings;
    public:
        scope();
        virtual ~scope();
        void closeScope(void);
        void initializeScope(const struct SCOPESETTINGS&);
        void getScopeData(const char* x, const struct SCOPESETTINGS&);
        //void getScopeData(std::string x);
};

#endif // SCOPE_H
