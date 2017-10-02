#include <stdio.h>
#include <objbase.h>

#include "DeckLinkAPI.h"

int main(int argc, char** argv)
{
    printf("%s Starts!\n", argv[0]);
    CoInitialize(NULL);

    IDeckLinkIterator* deckLinkIterator = NULL;
    if (S_OK == CoCreateInstance(CLSID_CDeckLinkIterator, NULL, CLSCTX_ALL, IID_IDeckLinkIterator, reinterpret_cast<void**>(&deckLinkIterator)))
    {
        IDeckLink* deckLinkInstance = NULL;
        if (S_OK == deckLinkIterator->Next(&deckLinkInstance))
        {
            deckLinkInstance->Release();
            deckLinkInstance = NULL;
        }
        deckLinkIterator->Release();
        deckLinkIterator = NULL;
    }

    CoUninitialize();
    printf("%s Completes!\n", argv[0]);
    return 1;
}
