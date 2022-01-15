#ifndef GTU_DOCUMENT_H
#define GTU_DOCUMENT_H

#include <iostream>
#include <string>

namespace gtu {
    template<typename T>
    class GTUDocument {
    public:
        string & at (int index) const;
        // returns the indexed line

        int find (const string & line) const;
        // returns the index of given line

        void insert (const string & line);
        // inserts given line at the end of the document
    protected:
        string doc[];
    };
}

/*
4 - c++ da template GTUDocument abstract class ı var. 
    text stringi verileri line olarak tutacak. 
    index verince line veren, line verince onun indexini veren, line girince line i insert eden fonksiyonlar vardı.
	
    GTUEmail class i GTUDocumentten türeyecek. GTUDictionary class ı vardı. Map<string, string> tipinde. fonksiyonlar override edilecek. Insert ve find fonksiyonları map in key ine göre arama ya da insert yapacaktı. 
	GTUDocument tipinde global fonksiyon vardı. GTUDictionary alacak ve key lere göre sort edecek . global fonksiyonu çağıran bir main yazılacaktı  ( 35 puan )
*/


#endif