# $NetBSD: Makefile,v 1.1 2013/03/03 21:15:03 othyro Exp $
#

DISTNAME=	opennurbs_20130711
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	devel
MASTER_SITES=	http://files.mcneel.com/opennurbs/5.0/2013-07-11/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.opennurbs.org/
COMMENT=	OSS toolkit for reading and writing models in the 3DM format
LICENSE=	2-clause-bsd AND zlib # XXX ?

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
MAKE_FILE=	makefile

INSTALLATION_DIRS+=	bin lib

do-install:
	for i in brep read roundtrip userdata write; do \
		${INSTALL_PROGRAM} ${WRKSRC}/example_$$i/example_$$i \
			${DESTDIR}${PREFIX}/bin/example_$$i; \
		done;
	${INSTALL_LIB} ${WRKSRC}/libopenNURBS.a ${DESTDIR}${PREFIX}/lib/

post-install:
	${CHMOD} -x ${DESTDIR}${PREFIX}/lib/libopenNURBS.a

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
