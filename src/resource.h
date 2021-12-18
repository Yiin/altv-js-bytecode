#pragma once

#include "cpp-sdk/SDK.h"
#include "v8.h"

class JSBytecodeRuntime;

class JSBytecodeResource : public alt::IResource::Impl
{
    v8::Isolate* isolate;
    v8::Persistent<v8::Context> context;
    alt::IResource* resource;

public:
    JSBytecodeResource(alt::IResource* resource, v8::Isolate* isolate) : resource(resource), isolate(isolate), context(isolate, v8::Context::New(isolate)) {}
    bool Stop() override;

    bool WriteClientFile(alt::IPackage* package, const std::string& fileName, void* buffer, uint64_t size) override;
};
