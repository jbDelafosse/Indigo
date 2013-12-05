#ifndef __fingerprint_table__
#define __fingerprint_table__

#include "base_cpp/scanner.h"
#include "base_cpp/output.h"
#include "base_cpp/tlscont.h"
#include "base_cpp/obj_array.h"
#include "math/algebra.h"
#include "time.h"
#include "new"
#include "bingo_sim_coef.h"
#include "bingo_container_set.h"
#include "bingo_ptr.h"

#include <vector>

using namespace indigo;
namespace bingo
{
   class FingerprintTable
   {
   public:
      FingerprintTable (int fp_size, const Array<int> &borders, int mt_size);

      static size_t create (BingoPtr<FingerprintTable> &ptr, int fp_size, int mt_size );

      static void load (BingoPtr<FingerprintTable> &ptr, size_t offset);

      void add (const byte *fingerprint, int id);

      void findSimilar (const byte *query, SimCoef &sim_coef, double min_coef, Array<SimResult> &sim_fp_indices);

      void optimize ();

      int getCellCount () const;

      int getCellSize (int cell_idx) const;
      
      void getCellsInterval (const byte *query, SimCoef &sim_coef, double min_coef, int &min_cell, int &max_cell);

      int firstFitCell (int query_bit_count, int min_cell, int max_cell ) const;

      int nextFitCell (int query_bit_count, int first_fit_cell, int min_cell, int max_cell, int idx) const;

      int getSimilar (const byte *query, SimCoef &sim_coef, double min_coef, 
                      Array<SimResult> &sim_fp_indices, int cell_idx, int cont_idx);

      ~FingerprintTable();
   
   private:

      BingoArray<ContainerSet> _table;
      int _max_cell_count;
      int _fp_size;
      int _mt_size;
   };
};

#endif /* __fingerprint_table__ */
