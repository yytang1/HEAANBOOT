#ifndef HEAAN_CIPHERTEXT_H_
#define HEAAN_CIPHERTEXT_H_

#include <NTL/ZZ.h>
#include <NTL/ZZX.h>

using namespace std;
using namespace NTL;

/**
 * Ciphertext is an RLWE instance (ax, bx = mx + ex - ax * sx) in ring Z_q[X] / (X^N + 1);
 */
class Ciphertext {
public:

	ZZX ax; ///< Ciphertext is an RLWE instance (ax, bx = mx + ex - ax * sx) in ring Z_q[X] / (X^N + 1);
	ZZX bx; ///< Ciphertext is an RLWE instance (ax, bx = mx + ex - ax * sx) in ring Z_q[X] / (X^N + 1);

	ZZ q; ///< Ciphertext modulus
	long logq; ///< number of bits in modulus
	long slots; ///< number of slots in Ciphertext

	bool isComplex; ///< option of Ciphertext with single real slot
	//-----------------------------------------

	/**
	 * Ciphertext = (ax, bx = mx + ex - ax * sx) for secret key sx and error ex
	 * @param[in] ax: ZZX polynomial
	 * @param[in] bx: ZZX polynomial
	 * @param[in] q: ciphertext modulus
	 * @param[in] logq: number of bits in modulus
	 * @param[in] slots: number of slots in a ciphertext
	 * @param[in] isComplex: option of Ciphertext with single real slot
	 */
	Ciphertext(ZZX ax = ZZX::zero(), ZZX bx = ZZX::zero(), ZZ q = ZZ::zero(), long logq = 0, long slots = 1, bool isComplex = true) : ax(ax), bx(bx), q(q), logq(logq), slots(slots), isComplex(isComplex) {}

	/**
	 * Copy Constructor
	 */
	Ciphertext(const Ciphertext& o) : ax(o.ax), bx(o.bx), q(o.q), logq(o.logq), slots(o.slots), isComplex(o.isComplex) {}

	/**
	 * Writing Ciphertext to the file by ID
	 */
	void Write(long CiphertextID);

	/**
	 * Reading Ciphertext from the file by ID
	 */
	void Read(long CiphertextID);

};

#endif
