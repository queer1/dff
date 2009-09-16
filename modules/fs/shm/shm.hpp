/* 
 * DFF -- An Open Source Digital Forensics Framework
 * Copyright (C) 2009 ArxSys
 * 
 * This program is free software, distributed under the terms of
 * the GNU General Public License Version 2. See the LICENSE file
 * at the top of the source tree.
 * 
 * See http://www.digital-forensic.org for more information about this
 * project. Please do not directly contact any of the maintainers of
 * DFF for assistance; the project provides a web site, mailing lists
 * and IRC channels for your use.
 * 
 * Author(s):
 *  Solal Jacob <sja@digital-forensic.org>
 *
 */

#ifndef __MEML_HH__
#define __MEM_HH__
#ifndef WIN32
#include <dlfcn.h>
#endif
#include <stdlib.h>
#include <string>
#include <stdlib.h>
#include <list>
#include <vector>
#include <map>
#include "type.hpp"
#include "vfs.hpp"
#include "conf.hpp"
#include "loader.hpp"

using namespace std;

class data
{
 public:
 void *buff;
 dff_ui64 size;
};

class odata
{
  public:
  dff_ui64 offset;
  int	 	handle;
};

class shm : public fso 
{
  private:
  vector<class data *> blist;
  vector<class odata *> olist;
  class Node*   root;
  public:
  shm(string dname) { name = dname; res = new results(name);  };
  ~shm() {};
  virtual void 	start(argument* arg);
  virtual int vopen(Handle* handle);
  virtual int vread(int fd, void *buff, unsigned int size);
  virtual int vclose(int fd);
  virtual dff_ui64 vseek(int fd, dff_ui64 offset, int whence); 
  virtual int vwrite(int fd, void *buff, unsigned int size);
  virtual unsigned int status(void);
};

#endif 
