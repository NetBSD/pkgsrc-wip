# $NetBSD: Makefile,v 1.5 2010/01/17 12:03:33 thomasklausner Exp $
#

DISTNAME=		west_0.9
PKGNAME=		west-0.9
PKGREVISION=		2
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=west/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://west.sourceforge.net/
COMMENT=		Web scripting/stress tool

WRKSRC=		${WRKDIR}/west

SUBST_CLASSES+=make
SUBST_STAGE.make=pre-build
SUBST_FILES.make=Makefile
SUBST_SED.make  =-e 's|CFLAGS\ =|CFLAGS=${CFLAGS}\ -I${PREFIX}/include/openssl/\#|g' \
		 -e 's|LDFLAGS\ =|LIBS+=${LDFLAGS}|g'

DOC_FILES=background.html index.html command_ref.html scripting.html

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/west ${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/west/
.for f in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/doc/$f ${PREFIX}/share/doc/west/
.endfor

.include "../../devel/pcre/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
