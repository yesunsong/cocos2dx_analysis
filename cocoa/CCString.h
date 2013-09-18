/****************************************************************************
Copyright (c) 2010 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
#ifndef __CCSTRING_H__
#define __CCSTRING_H__

#if (CC_TARGET_PLATFORM == CC_PLATFORM_BLACKBERRY)
#include <string.h>
#endif

#include <stdarg.h>
#include <string>
#include <functional>
#include "CCObject.h"

NS_CC_BEGIN

/**
 * @addtogroup data_structures
 * @{
 */

class CC_DLL CCString : public CCObject
{
public:
    CCString();
    CCString(const char* str);
    CCString(const std::string& str);
    CCString(const CCString& str);

    virtual ~CCString();
    
    /* override assignment operator */
    CCString& operator= (const CCString& other);

    /** init a string with format, it's similar with the c function 'sprintf' */ 
    bool initWithFormat(const char* format, ...) CC_FORMAT_PRINTF(2, 3);

    /** convert to int value */
    /** 转为int值 */
    int intValue() const;

    /** convert to unsigned int value */
    /** 转为无符号int值 */
    unsigned int uintValue() const;

    /** convert to float value */
    /** 转为float值 */
    float floatValue() const;

    /** convert to double value */
    /** 转为double值 */
    double doubleValue() const;

    /** convert to bool value */
    /** 转为bool值 */
    bool boolValue() const;

    /** get the C string */
    /** 获取c语言的字符串 */
    const char* getCString() const;

    /** get the length of string */
    /** 获取字符串的长度 */
    unsigned int length() const;

    /** compare to a c string */
    /** 比较c字符串 */
    int compare(const char *) const;

    /* override functions */
    virtual CCObject* copyWithZone(CCZone* pZone);
    virtual bool isEqual(const CCObject* pObject);

    /** create a string with std string, you can also pass a c string pointer because the default constructor of std::string can access a c string pointer. 
     *  @return A CCString pointer which is an autorelease object pointer,
     *          it means that you needn't do a release operation unless you retain it.
     */
    /**使用std::string创建了一个字符串, 你也可以传递一个c字符串指针，因为std：：string的构造函数可以访问c字符串指针     
     * @返回的 CCString 指针是一个自动释放对象,     
     *也就意味着你不需要调用release操作，除非你retain了.     
     */
    static CCString* create(const std::string& str);

    /** create a string with format, it's similar with the c function 'sprintf', the default buffer size is (1024*100) bytes,
     *  if you want to change it, you should modify the kMaxStringLen macro in CCString.cpp file.
     *  @return A CCString pointer which is an autorelease object pointer,
     *          it means that you needn't do a release operation unless you retain it.
     */
    /**使用格式化方式来创建一个字符串，这个方法和c语言里面的‘sprintf’类似,默认缓存大小是（1024*100）bytes     
     *假如你想要改变这个缓存大小，你可以去CCString.cpp中，更改kMaxStringLen 这个宏定义。 
     * @返回的 CCString 指针是一个自动释放对象,     
     *也就意味着你不需要调用release操作，除非你retain了.     
     */
    static CCString* createWithFormat(const char* format, ...) CC_FORMAT_PRINTF(1, 2);

    /** create a string with binary data 
     *  @return A CCString pointer which is an autorelease object pointer,
     *          it means that you needn't do a release operation unless you retain it.
     */
    /** 使用二进制数据来创建字符串     
     * @返回的 CCString 指针是一个自动释放对象,     
     *也就意味着你不需要调用release操作，除非你retain了.     
     */
    static CCString* createWithData(const unsigned char* pData, unsigned long nLen);

    /** create a string with a file, 
     *  @return A CCString pointer which is an autorelease object pointer,
     *          it means that you needn't do a release operation unless you retain it.
     */
    /**使用一个文件来创建一个字符串,     
     * @返回的 CCString 指针是一个自动释放对象,      
     * 也就意味着你不需要调用release操作，除非你retain了.      
     */
    static CCString* createWithContentsOfFile(const char* pszFileName);

    virtual void acceptVisitor(CCDataVisitor &visitor);

private:

    /** only for internal use */
    bool initWithFormatAndValist(const char* format, va_list ap);

public:
    std::string m_sString;
};

struct CCStringCompare : public std::binary_function<CCString *, CCString *, bool> {
    public:
        bool operator() (CCString * a, CCString * b) const {
            return strcmp(a->getCString(), b->getCString()) < 0;
        }
};
//宏定义，可以非常方便的构建一个自动释放的CCString对象
#define CCStringMake(str) CCString::create(str)
#define ccs               CCStringMake

// end of data_structure group
/// @}

NS_CC_END

#endif //__CCSTRING_H__
