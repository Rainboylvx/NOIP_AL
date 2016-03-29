/*  模版: 1.对拍  2.代码测试
 *      
 *
 * */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <io.h>

char extname[100]={0};

void get_extension(const char *file_name,char *extension)  
{  
    int i=0,length;  
    length=strlen(file_name);  
   while(file_name[i])  
    {  
        if(file_name[i]=='.')  
        break;  
        i++;  
    }  
    if(i<length)  
    strcpy(extension,file_name+i+1);  
    else  
    strcpy(extension,"\0");  
} 

void getFiles()//get local files  
{  
    //文件句柄  
    long   hFile   =   0;  
    //文件信息  
    struct _finddata_t fileinfo;  
    if((hFile = _findfirst("./*",&fileinfo)) !=  -1)  
    {  
        do  
        {  
            //如果是目录,迭代之  
            //如果不是,加入列表  
            if((fileinfo.attrib &  _A_SUBDIR))  
            {  
					;//do nothing
            }  
            else  
            {  
                //files.push_back(p.assign(path).append("\\").append(fileinfo.name) );
				printf("%s\t",fileinfo.name);
				get_extension(fileinfo.name,extname);
				printf("%s\n",extname);
            }  
        }while(_findnext(hFile, &fileinfo)  == 0);  
        _findclose(hFile);  
    }  
}

int main(){
	
	getFiles();
	//system("gcc -v");
	return 0;
}
