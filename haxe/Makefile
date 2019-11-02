# $NetBSD: Makefile,v 1.20 2019/08/27 19:56:03 schmonz Exp $

GITHUB_PROJECT=	haxe
DISTNAME=	haxe-4.0.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=HaxeFoundation/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ocaml-community/sedlex
COMMENT=	Programming language that produces cross-platofrm binaries
LICENSE=	isc

DIST_SUBDIR=	${PKGBASE}

HAXELIB=	haxelib
HAXELIB_TAG=	4.0.0
SITES.${HAXELIB}-${HAXELIB_TAG}.tar.gz=	\
	-https://codeload.github.com/HaxeFoundation/haxelib/tar.gz/${HAXELIB_TAG}

HXCOMPAT=	hx3compat
HXCOMPAT_TAG=	ae0d8a85666199b52aed8987c9feaf297c3f66d4
SITES.${HXCOMPAT_TAG}.tar.gz=	\
	-https://codeload.github.com/HaxeFoundation/hx3compat/tar.gz/${HXCOMPAT_TAG}

DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} ${HAXELIB}-${HAXELIB_TAG}.tar.gz ${HXCOMPAT_TAG}.tar.gz

USE_TOOLS+=	gmake

SUBST_CLASSES+=		pcreinc
SUBST_STAGE.pcreinc=	pre-configure
SUBST_FILES.pcreinc=	libs/pcre/Makefile
SUBST_VARS.pcreinc=	PREFIX

MAKE_JOBS_SAFE=		no

post-extract:
	${CP} -pR ${WRKDIR}/${HAXELIB}-${HAXELIB_TAG}/* ${WRKSRC}/extra/haxelib_src/
	${CP} -pR ${WRKDIR}/${HXCOMPAT}-${HXCOMPAT_TAG}/* ${WRKSRC}/extra/haxelib_src/hx3compat

DEPENDS+=	neko-[0-9]*:../../wip/neko

.include "../../wip/ocaml-ptmap/buildlink3.mk"
.include "../../wip/ocaml-sha/buildlink3.mk"
.include "../../wip/ocaml-sedlex/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../devel/ocaml-dune/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
