#ifndef SCOPE_H
#define SCOPE_H

class scope
{
    public:
        scope();
        void closeScope();
        void initializeScope(const struct SCOPESETTINGS&);
        void getScopeData(const char* x, const struct SCOPESETTINGS&);
};

#endif // SCOPE_H
