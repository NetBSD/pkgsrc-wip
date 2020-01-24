# $NetBSD: Makefile,v 1.8 2012/12/09 17:02:05 othyro Exp $
#

DISTNAME=	west_0.9
PKGNAME=	${DISTNAME:S/_/-/1}
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=west/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://west.sourceforge.net/
COMMENT=	Web scripting/stress tool
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/west

SUBST_CLASSES+=		make
SUBST_STAGE.make=	pre-build
SUBST_FILES.make=	Makefile
SUBST_SED.make=		-e 's|CFLAGS\ =|CFLAGS=${CFLAGS}\ -I${PREFIX}/include/openssl/\#|g'
SUBST_SED.make+=	-e 's|LDFLAGS\ =|LIBS+=${LDFLAGS}|g'

DOC_FILES=		background.html index.html command_ref.html
DOC_FILES+=		scripting.html

INSTALLATION_DIRS=	bin share/doc/${PKGBASE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/west ${DESTDIR}${PREFIX}/bin
.for f in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
.endfor

.include "../../devel/pcre/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
