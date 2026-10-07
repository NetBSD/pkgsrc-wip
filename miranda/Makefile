# $NetBSD$

DISTNAME=		miranda-2.069
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_CODEBERG:=DATurner/}
CODEBERG_RELEASE=	${DISTNAME}
# https://codeberg.org/DATurner/miranda/releases/download/miranda-2.068/miranda-2.068.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://miranda.org.uk/
COMMENT=	pure, non-strict, polymorphic, functional programming language
#LICENSE=	# TODO: (see mk/license.mk)

USE_TOOLS+=	gmake

INSTALLATION_DIRS=      bin lib ${PKGMANDIR}/man1

TOOL_DEPENDS+=	byacc-[0-9]*:../../devel/byacc/

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix+=	Makefile
SUBST_FILES.prefix+=	steer.c
SUBST_VARS.prefix=	PREFIX PKGMANDIR

REPLACE_INTERPRETER+=	mira
REPLACE.mira.old=	.*/mira
REPLACE.mira.new=	${PREFIX}/bin/mira
REPLACE_FILES.mira+=	miralib/ex/box
REPLACE_FILES.mira+=	miralib/ex/box.m
REPLACE_FILES.mira+=	miralib/ex/mrev

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
