// RUN: %dxc -T lib_6_8 -ast-dump-implicit %s FileCheck %s
// This test verifies the AST of the RW{Dispatch|Group|Thread}NodeInputRecord{s} types.
// The source doesn't matter except that it forces a use to ensure the AST is fully
// loaded by the external sema source.

struct RECORD
{
  int X;
};

[Shader("node")]
[NodeLaunch("Broadcasting")]
[NumThreads(1024,1,1)]
[NodeDispatchGrid(64,1,1)]
void node05(RWDispatchNodeInputRecord<RECORD> input) {}

//CHECK: ClassTemplateDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> implicit RWDispatchNodeInputRecord
//CHECK-NEXT: TemplateTypeParmDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> class recordtype 
//CHECK-NEXT: CXXRecordDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> implicit struct RWDispatchNodeInputRecord definition
//CHECK-NEXT: FinalAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit final
//CHECK-NEXT: FieldDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> implicit h 'int'
//CHECK-NEXT: CXXMethodDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> Get 'recordtype &()'
//CHECK-NEXT: HLSLIntrinsicAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit "op" "ExtractRecordStructFromArray" 18
//CHECK-NEXT: HLSLCXXOverloadAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit
//CHECK-NEXT: CXXMethodDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> Get 'const recordtype &() const'
//CHECK-NEXT: HLSLIntrinsicAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit "op" "ExtractRecordStructFromArray" 18
//CHECK-NEXT: HLSLCXXOverloadAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit
//CHECK-NEXT: FunctionTemplateDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> FinishedCrossGroupSharing
//CHECK-NEXT: TemplateTypeParmDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> class TResult
//CHECK-NEXT: CXXMethodDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> implicit FinishedCrossGroupSharing 'TResult () const'
//CHECK-NEXT: ClassTemplateSpecializationDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> struct RWDispatchNodeInputRecord definition
//CHECK-NEXT: TemplateArgument type 'RECORD'
//CHECK-NEXT: FinalAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit final
//CHECK-NEXT: FieldDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> implicit h 'int'
//CHECK-NEXT: CXXMethodDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> Get 'RECORD &()'
//CHECK-NEXT: HLSLIntrinsicAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit "op" "ExtractRecordStructFromArray" 18
//CHECK-NEXT: HLSLCXXOverloadAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit
//CHECK-NEXT: CXXMethodDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> Get 'const RECORD &() const'
//CHECK-NEXT: HLSLIntrinsicAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit "op" "ExtractRecordStructFromArray" 18
//CHECK-NEXT: HLSLCXXOverloadAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit
//CHECK-NEXT: FunctionTemplateDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> FinishedCrossGroupSharing
//CHECK-NEXT: TemplateTypeParmDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> class TResult
//CHECK-NEXT: CXXMethodDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> FinishedCrossGroupSharing 'TResult () const'

[Shader("node")]
[NodeLaunch("Coalescing")]
[NumThreads(1024,1,1)]
void node06(RWGroupNodeInputRecords<RECORD> input) {}

//CHECK: ClassTemplateDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> implicit RWGroupNodeInputRecords
//CHECK-NEXT: TemplateTypeParmDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> class recordtype
//CHECK-NEXT: CXXRecordDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> implicit struct RWGroupNodeInputRecords
//CHECK-NEXT: FinalAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit final
//CHECK-NEXT: FieldDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> implicit h 'int'
//CHECK-NEXT: CXXMethodDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> Get 'recordtype &(unsigned int)'
//CHECK-NEXT: ParmVarDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> Index 'unsigned int' cinit
//CHECK-NEXT: IntegerLiteral {{0x[0-9a-fA-F]+}} <<invalid sloc>> 'unsigned int' 0
//CHECK-NEXT: HLSLIntrinsicAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit "op" "ExtractRecordStructFromArray" 18
//CHECK-NEXT: HLSLCXXOverloadAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit
//CHECK-NEXT: CXXMethodDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> Get 'const recordtype &(unsigned int) const'
//CHECK-NEXT: ParmVarDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> Index 'unsigned int' cinit
//CHECK-NEXT: IntegerLiteral {{0x[0-9a-fA-F]+}} <<invalid sloc>> 'unsigned int' 0
//CHECK-NEXT: HLSLIntrinsicAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit "op" "ExtractRecordStructFromArray" 18
//CHECK-NEXT: HLSLCXXOverloadAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit
//CHECK-NEXT: CXXMethodDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> operator[] 'recordtype &(unsigned int)'
//CHECK-NEXT: ParmVarDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> Index 'unsigned int'
//CHECK-NEXT: HLSLIntrinsicAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit "op" "ExtractRecordStructFromArray" 18
//CHECK-NEXT: HLSLCXXOverloadAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit
//CHECK-NEXT: CXXMethodDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> operator[] 'const recordtype &(unsigned int) const'
//CHECK-NEXT: ParmVarDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> Index 'unsigned int'
//CHECK-NEXT: HLSLIntrinsicAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit "op" "ExtractRecordStructFromArray" 18
//CHECK-NEXT: HLSLCXXOverloadAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit
//CHECK-NEXT: FunctionTemplateDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> operator[]
//CHECK-NEXT: TemplateTypeParmDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> class recordtype
//CHECK-NEXT: CXXMethodDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> operator[] 'const recordtype &(unsigned int) const'
//CHECK-NEXT: ParmVarDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> index 'unsigned int'
//CHECK-NEXT: HLSLCXXOverloadAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit
//CHECK-NEXT: FunctionTemplateDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> Count
//CHECK-NEXT: TemplateTypeParmDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> class TResult
//CHECK-NEXT: CXXMethodDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> implicit Count 'TResult () const'

//CHECK-NEXT: ClassTemplateSpecializationDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> struct RWGroupNodeInputRecords definition
//CHECK-NEXT: TemplateArgument type 'RECORD'
//CHECK-NEXT: FinalAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit final
//CHECK-NEXT: FieldDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> implicit h 'int'
//CHECK-NEXT: CXXMethodDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> Get 'recordtype &(unsigned int)'
//CHECK-NEXT: ParmVarDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> Index 'unsigned int' cinit
//CHECK-NEXT: IntegerLiteral {{0x[0-9a-fA-F]+}} <<invalid sloc>> 'unsigned int' 0
//CHECK-NEXT: CXXMethodDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> Get 'const RECORD &(unsigned int) const'
//CHECK-NEXT: ParmVarDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> Index 'unsigned int'
//CHECK-NEXT: HLSLIntrinsicAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit "op" "ExtractRecordStructFromArray" 18
//CHECK-NEXT: HLSLCXXOverloadAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit
//CHECK-NEXT: CXXMethodDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> operator[] 'recordtype &(unsigned int)'
//CHECK-NEXT: ParmVarDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> Index 'unsigned int'
//CHECK-NEXT: HLSLIntrinsicAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit "op" "ExtractRecordStructFromArray" 18
//CHECK-NEXT: HLSLCXXOverloadAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit
//CHECK-NEXT: CXXMethodDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> operator[] 'const RECORD &(unsigned int) const'
//CHECK-NEXT: ParmVarDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> Index 'unsigned int'
//CHECK-NEXT: HLSLIntrinsicAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit "op" "ExtractRecordStructFromArray" 18
//CHECK-NEXT: HLSLCXXOverloadAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit
//CHECK-NEXT: FunctionTemplateDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> operator[]
//CHECK-NEXT: TemplateTypeParmDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> class recordtype
//CHECK-NEXT: CXXMethodDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> operator[] 'const recordtype &(unsigned int) const'
//CHECK-NEXT: ParmVarDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> index 'unsigned int'
//CHECK-NEXT: HLSLCXXOverloadAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit
//CHECK-NEXT: FunctionTemplateDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> Count
//CHECK-NEXT: TemplateTypeParmDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> class TResult
//CHECK-NEXT: CXXMethodDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> Count 'TResult () const'

[Shader("node")]
[NodeLaunch("Thread")]
void node07(RWThreadNodeInputRecord<RECORD> input) {}

//CHECK: ClassTemplateDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> implicit RWThreadNodeInputRecord
//CHECK-NEXT: TemplateTypeParmDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> class recordtype
//CHECK-NEXT: CXXRecordDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> implicit struct RWThreadNodeInputRecord definition
//CHECK-NEXT: FinalAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit final
//CHECK-NEXT: FieldDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> implicit h 'int'
//CHECK-NEXT: CXXMethodDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> Get 'recordtype &()'
//CHECK-NEXT: HLSLIntrinsicAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit "op" "ExtractRecordStructFromArray" 18
//CHECK-NEXT: HLSLCXXOverloadAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit
//CHECK-NEXT: CXXMethodDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> Get 'const recordtype &() const'
//CHECK-NEXT: HLSLIntrinsicAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit "op" "ExtractRecordStructFromArray" 18
//CHECK-NEXT: HLSLCXXOverloadAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit
//CHECK-NEXT: FunctionTemplateDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> FinishedCrossGroupSharing
//CHECK-NEXT: TemplateTypeParmDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> class TResult
//CHECK-NEXT: CXXMethodDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> implicit FinishedCrossGroupSharing 'TResult () const'
//CHECK-NEXT: ClassTemplateSpecializationDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> struct RWThreadNodeInputRecord definition
//CHECK-NEXT: TemplateArgument type 'RECORD'
//CHECK-NEXT: FinalAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit final
//CHECK-NEXT: FieldDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> implicit h 'int'
//CHECK-NEXT: CXXMethodDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> Get 'RECORD &()'
//CHECK-NEXT: HLSLIntrinsicAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit "op" "ExtractRecordStructFromArray" 18
//CHECK-NEXT: HLSLCXXOverloadAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit
//CHECK-NEXT: CXXMethodDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> Get 'const RECORD &() const'
//CHECK-NEXT: HLSLIntrinsicAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit "op" "ExtractRecordStructFromArray" 18
//CHECK-NEXT: HLSLCXXOverloadAttr {{0x[0-9a-fA-F]+}} <<invalid sloc>> Implicit
//CHECK-NEXT: FunctionTemplateDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> FinishedCrossGroupSharing
//CHECK-NEXT: TemplateTypeParmDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> class TResult
//CHECK-NEXT: CXXMethodDecl {{0x[0-9a-fA-F]+}} <<invalid sloc>> <invalid sloc> FinishedCrossGroupSharing 'TResult () const'
