# $NetBSD: Makefile,v 1.2 2004/03/17 20:47:57 airhead Exp $
#

DISTNAME=		cl74unix
PKGNAME=		caml-libunix-0.74
WRKSRC=			${WRKDIR}/cl74/contrib/libunix
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.inria.fr/lang/caml-light/

MAINTAINER=		airhead@users.sf.net
HOMEPAGE=		http://caml.inria.fr/distrib-caml-light-eng.html
COMMENT=		Libunix from CAML-light contrib dir

DEPENDS+=		caml-light-[0-9]*:../../lang/caml-light

do-configure:
	(cd ${WRKDIR}/cl74/src && make configure)

post-configure:
	${ECHO} '#define HAS_STRERROR' >> ${WRKDIR}/cl74/config/s.h

.include "../../mk/bsd.pkg.mk"
