#pragma once

// TODO: Check this

// This is a 'forward declaration', and is used to let other
// classes know that SimpleClass exists. To understand this
// let's think about SimpleClass and FriendFunctionClass.

// The SimpleClass header needs to know FriendFunctionClass 
// exists in order to let the compiler know one of its methods 
// is allowed access to its data. 

// The FriendFunctionClass header needs to know SimpleClass 
// exists in order to declare the print function, which takes 
// SimpleClass as an argument.

// We have a cyclic dependency, which we need to break. 

// In order to do this we can provide a forward declaration to the
// FriendFunctionClass header to say 'SimpleClass does exist, but 
// you don't need to know anything about its contents'. This is enough 
// to satisfy the compiler.

// Then, when we do need to know about the contents (i.e. in the 
// implementation of FriendFunctionClass), we can include the 'true'
// header file.
class SimpleClass;