// Rewrite unchanged result:


float f_arr_empty_init[] = { 1, 2, 3 };


struct s_arr_i_f { int i; float f; };
s_arr_i_f arr_struct_none[] = { };
s_arr_i_f arr_struct_one[] = { 1, 2 };

s_arr_i_f arr_struct_two[] = { 1, 2, 3, 4 };

int g_int;
unsigned int g_unsigned_int;
#pragma align(4)
static int static_int() { return 1; }
int is_supported() {
  return 0;
}
typedef void VOID_TYPE;
float4 fn_with_semantic() : SV_Target0{
  return 0;
}

float4 fn_with_semantic_arg(float4 arg : SV_SOMETHING) : SV_Target0{
  return arg;
}
namespace MyNS {
}
namespace MyNs {
  int my_ns_extension;
}
namespace MyNs2
{
  float outsideFunc(int x);
}
float MyNs2::outsideFunc(int x)
{
  return x;
}
float4 main()
{
  return MyNs2::outsideFunc(1);
}

struct my_struct { };

class my_class { };

interface my_interface { };

class my_class_2 : my_class { };

class my_class_3 : my_interface { };

class my_class_4 : my_struct { };

struct my_struct_2 : my_struct { };

struct my_struct_3 : my_class { };

struct my_struct_4 : my_interface { };
struct my_struct_5 : my_class, my_interface { };







struct my_struct_type_decl { int a; } my_struct_var_decl;


struct my_struct_type_init { int a; } my_struct_type_init_one = { 1 }, my_struct_type_init_two = { 2 };

struct { int my_anon_struct_field; } my_anon_struct_type;

void fn_my_struct_type_decl() {
  my_struct_type_decl local_var;
}
struct s_with_multiple {
  int i, j;
};
class c_outer_fn {
  int fn() {
    class local_class { int j; };
    typedef int local_int;
 return 0;
  }
};





namespace ns_with_struct {
  struct s { int i; };
}



matrix<int, 1, 2> g_matrix_simple;






#pragma unknown

int global_fn() { return 1; }


void statements()
{
  int local_i = 1;
  {

    float local_f;
  }
  {

    double local_f;
  }







  (void)local_i;


  if (local_i == 0) {
    local_i++;
  }

  if (int my_if_local = global_fn()) {
    local_i++;
    my_if_local++;
  } else {
    my_if_local--;
  }



  switch (int my_switch_local = global_fn()) {
  case 0: my_switch_local--; return;
  }
  while (int my_while_local = global_fn()) {
    my_while_local--;
  }

  switch(local_i) {
  case 0:
    local_i = 2;
    break;
  case 1 + 2:
    local_i = 3;
    break;




  default:
    local_i = 100;

  }

  while (local_i > 0) {
    local_i -= 1;
    if (local_i == 1) continue;
    if (local_i == 2) break;
  }
  do local_i += 1; while (local_i < 3);


  for (int i = 0; i < 10; ++i) {
    local_i = i;
    break;
  }
  local_i = i - 1;

  for (int val = 0; i < 10; ++i) {
    int val_inner = val;
    break;
  }
  for (local_i = 0; ;) {
    break;
  }

  for (int j;;) { break; }
  if (local_i == 0)
    local_i = 1;
  else {
    local_i = 2;
  }


  ;;;
  return;


  discard;
}

void expressions()
{
  int local_i;
  local_i = 1 > 2 ? 0 : 1;







  local_i = true;






  local_i = 'c';
  local_i = '\xFF';
  local_i = '\x94';







  local_i = +local_i;
  local_i = -local_i;
  local_i = ~local_i;
  local_i = !local_i;




  struct CInternal {
    int i;
    int fn() { return this.i; }
    CInternal getSelf() { return this; }

  };


  CInternal internal;
}



int unused_i;
#pragma unused(unused_i)
#pragma unknown
#pragma GCC visibility push(public)
#pragma pack(push, 1)
#pragma ms_struct(on)
#pragma comment(lib, "kernel32.lib")
#pragma align 64
#pragma weak expressions
#pragma weak expressions = expressions
#pragma redefine_extname g_int new_name_g_int
#pragma STDC FP_CONTRACT on
#pragma OPENCL EXTENSION
#pragma clang __debug captured
#pragma




float4 plain(float4 param4 ) {



  return is_supported();
}
