# $NetBSD: Makefile,v 1.2 2004/03/24 21:21:59 airhead Exp $
#

DISTNAME=		holl-1.0
PKGNAME=		hol-light-1.0
WRKSRC=			${WRKDIR}/hol-light
CATEGORIES=		wip math
MASTER_SITES=		http://www.cl.cam.ac.uk/users/jrh/hol-light/

MAINTAINER=		airhead@users.sf.net
HOMEPAGE=		http://www.cl.cam.ac.uk/users/jrh/hol-light/
COMMENT=		HOL Light theorem prover

DEPENDS+=		caml-light>=0.74:../../lang/caml-light
DEPENDS+=		caml-libunix>=0.74:../../wip/caml-libunix
DEPENDS+=		caml-libnum>=0.74:../../wip/caml-libnum

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o hol-filter filter.c)

post-patch:
	@${CP} ${WRKSRC}/caml ${WRKSRC}/caml.patched
	@${SED} -e "s,@HOLDIR@,${PREFIX}/lib/caml-light,g" \
	< ${WRKSRC}/caml.patches > ${WRKSRC}/caml

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hol-filter ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/caml ${PREFIX}/bin/holrun
	${INSTALL_DATA} ${WRKSRC}/arith.ml ${PREFIX}/lib/caml-light
	${INSTALL_DATA} ${WRKSRC}/basics.ml ${PREFIX}/lib/caml-light
	${INSTALL_DATA} ${WRKSRC}/bool.ml ${PREFIX}/lib/caml-light
	${INSTALL_DATA} ${WRKSRC}/calc_num.ml ${PREFIX}/lib/caml-light
	${INSTALL_DATA} ${WRKSRC}/calc_rat.ml ${PREFIX}/lib/caml-light
	${INSTALL_DATA} ${WRKSRC}/canon.ml ${PREFIX}/lib/caml-light
	${INSTALL_DATA} ${WRKSRC}/class.ml ${PREFIX}/lib/caml-light
	${INSTALL_DATA} ${WRKSRC}/drule.ml ${PREFIX}/lib/caml-light
	${INSTALL_DATA} ${WRKSRC}/equal.ml ${PREFIX}/lib/caml-light
	${INSTALL_DATA} ${WRKSRC}/hol.ml ${PREFIX}/lib/caml-light
	${INSTALL_DATA} ${WRKSRC}/ind-defs.ml ${PREFIX}/lib/caml-light
	${INSTALL_DATA} ${WRKSRC}/ind-types.ml ${PREFIX}/lib/caml-light
	${INSTALL_DATA} ${WRKSRC}/int.ml ${PREFIX}/lib/caml-light
	${INSTALL_DATA} ${WRKSRC}/itab.ml ${PREFIX}/lib/caml-light
	${INSTALL_DATA} ${WRKSRC}/lib.ml ${PREFIX}/lib/caml-light
	${INSTALL_DATA} ${WRKSRC}/list.ml ${PREFIX}/lib/caml-light
	${INSTALL_DATA} ${WRKSRC}/meson.ml ${PREFIX}/lib/caml-light
	${INSTALL_DATA} ${WRKSRC}/nets.ml ${PREFIX}/lib/caml-light
	${INSTALL_DATA} ${WRKSRC}/num.ml ${PREFIX}/lib/caml-light
	${INSTALL_DATA} ${WRKSRC}/pair.ml ${PREFIX}/lib/caml-light
	${INSTALL_DATA} ${WRKSRC}/parser.ml ${PREFIX}/lib/caml-light
	${INSTALL_DATA} ${WRKSRC}/preterm.ml ${PREFIX}/lib/caml-light
	${INSTALL_DATA} ${WRKSRC}/printer.ml ${PREFIX}/lib/caml-light
	${INSTALL_DATA} ${WRKSRC}/quot.ml ${PREFIX}/lib/caml-light
	${INSTALL_DATA} ${WRKSRC}/real.ml ${PREFIX}/lib/caml-light
	${INSTALL_DATA} ${WRKSRC}/realax.ml ${PREFIX}/lib/caml-light
	${INSTALL_DATA} ${WRKSRC}/recursion.ml ${PREFIX}/lib/caml-light
	${INSTALL_DATA} ${WRKSRC}/sets.ml ${PREFIX}/lib/caml-light
	${INSTALL_DATA} ${WRKSRC}/simp.ml ${PREFIX}/lib/caml-light
	${INSTALL_DATA} ${WRKSRC}/tactics.ml ${PREFIX}/lib/caml-light
	${INSTALL_DATA} ${WRKSRC}/term.ml ${PREFIX}/lib/caml-light
	${INSTALL_DATA} ${WRKSRC}/theorems.ml ${PREFIX}/lib/caml-light
	${INSTALL_DATA} ${WRKSRC}/thm.ml ${PREFIX}/lib/caml-light
	${INSTALL_DATA} ${WRKSRC}/trivia.ml ${PREFIX}/lib/caml-light
	${INSTALL_DATA} ${WRKSRC}/type.ml ${PREFIX}/lib/caml-light
	${INSTALL_DATA} ${WRKSRC}/wf.ml ${PREFIX}/lib/caml-light

.include "../../mk/bsd.pkg.mk"
