# $NetBSD: Makefile,v 1.4 2015/05/28 05:36:12 phonohawk Exp $
#

DISTNAME=	pib-0.3.1
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	http://d.tir.jp/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://legacy.e.tir.jp/wiliki?pib
COMMENT=	Gauche library for the IRC protocol
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

.include "../../lang/gauche/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# Substitute the path to sitelibdir in the PLIST.
.if exists(${PREFIX:Q}/bin/gauche-config)
GAUCHE_SITE_LIB_DIR!=	${PREFIX}/bin/gauche-config --sitelibdir
.endif
PLIST_SUBST+=		GAUCHE_SITE_LIB_DIR=${GAUCHE_SITE_LIB_DIR:S|${PREFIX}/||:Q}
PRINT_PLIST_AWK+=	\
	{ gsub(/${GAUCHE_SITE_LIB_DIR:S|${PREFIX}/||:S|/|\\/|g}/, \
	"$${GAUCHE_SITE_LIB_DIR}"); \
	}
