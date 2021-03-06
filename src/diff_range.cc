/**
 * This code is auto-generated; unless you know what you're doing, do not modify!
 **/
#include <v8.h>
#include <node.h>
#include <string.h>

#include "git2.h"

#include "../include/functions/copy.h"

#include "../include/diff_range.h"

using namespace v8;
using namespace node;

GitDiffRange::GitDiffRange(git_diff_range *raw) {
  this->raw = raw;
}

GitDiffRange::~GitDiffRange() {
  free(this->raw);
}

void GitDiffRange::Initialize(Handle<v8::Object> target) {
  NanScope();

  Local<FunctionTemplate> tpl = FunctionTemplate::New(New);

  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(NanSymbol("DiffRange"));

  NODE_SET_PROTOTYPE_METHOD(tpl, "oldStart", OldStart);
  NODE_SET_PROTOTYPE_METHOD(tpl, "oldLines", OldLines);
  NODE_SET_PROTOTYPE_METHOD(tpl, "newStart", NewStart);
  NODE_SET_PROTOTYPE_METHOD(tpl, "newLines", NewLines);

  NanAssignPersistent(FunctionTemplate, constructor_template, tpl);
  target->Set(String::NewSymbol("DiffRange"), tpl->GetFunction());
}

NAN_METHOD(GitDiffRange::New) {
  NanScope();

  if (args.Length() == 0 || !args[0]->IsExternal()) {
    return NanThrowError(String::New("git_diff_range is required."));
  }

  GitDiffRange* object = new GitDiffRange((git_diff_range *) External::Cast(*args[0])->Value());
  object->Wrap(args.This());

  NanReturnValue(args.This());
}

Handle<Value> GitDiffRange::New(void *raw) {
  NanScope();
  Handle<Value> argv[1] = { External::New((void *)raw) };
  Local<Object> instance;
  Local<FunctionTemplate> constructorHandle = NanPersistentToLocal(constructor_template);
  instance = constructorHandle->GetFunction()->NewInstance(1, argv);
  return scope.Close(instance);
}

git_diff_range *GitDiffRange::GetValue() {
  return this->raw;
}

NAN_METHOD(GitDiffRange::OldStart) {
  NanScope();
    Handle<Value> to;

  int old_start =
    ObjectWrap::Unwrap<GitDiffRange>(args.This())->GetValue()->old_start;

    to = Integer::New(old_start);
  NanReturnValue(to);
}

NAN_METHOD(GitDiffRange::OldLines) {
  NanScope();
    Handle<Value> to;

  int old_lines =
    ObjectWrap::Unwrap<GitDiffRange>(args.This())->GetValue()->old_lines;

    to = Integer::New(old_lines);
  NanReturnValue(to);
}

NAN_METHOD(GitDiffRange::NewStart) {
  NanScope();
    Handle<Value> to;

  int new_start =
    ObjectWrap::Unwrap<GitDiffRange>(args.This())->GetValue()->new_start;

    to = Integer::New(new_start);
  NanReturnValue(to);
}

NAN_METHOD(GitDiffRange::NewLines) {
  NanScope();
    Handle<Value> to;

  int new_lines =
    ObjectWrap::Unwrap<GitDiffRange>(args.This())->GetValue()->new_lines;

    to = Integer::New(new_lines);
  NanReturnValue(to);
}

Persistent<FunctionTemplate> GitDiffRange::constructor_template;
