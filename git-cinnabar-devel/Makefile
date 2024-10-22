# $NetBSD: Makefile,v 1.4 2023/09/26 07:38:58 wiz Exp $

PKGNAME=	git-cinnabar-0.7.0beta2
PKGREVISION=	20241022
CATEGORIES=	devel
# MASTER_SITES=	${MASTER_SITE_GITHUB:=glandium/}
# # does not contain the git submodules, please update GITHUB_SUBMODULES below
# GITHUB_TAG=	${PKGVERSION_NOREV}

GIT_REPO=	https://github.com/glandium/git-cinnabar.git
GIT_BRANCH=	try
#GIT_REVISION=	4fb9f8dcf2f566d6fb411adb198cfeb73f2cb564
DEFAULT_DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/glandium/git-cinnabar/
COMMENT=	Remote helper to use mercurial repositories with git
LICENSE=	mpl-2.0 AND gnu-gpl-v2

DEPENDS+=	git-base-[0-9]*:../../devel/git-base

#GITHUB_SUBMODULES=	git-for-windows git v2.41.0.windows.1 git-core

USE_TOOLS+=	gmake pkg-config

RUST_REQ=	1.66.0
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.curl}/lib

# This has to come before -I/usr/include/krb5 (which comes in on NetBSD
# via curl with gssapi enabled) because both git-core and krb5 have a
# file called `hex.h' which git-core uses internally.
CPPFLAGS+=	-I${WRKSRC}/git-core

INSTALLATION_DIRS+=	libexec/git-core share/doc/git-cinnabar

CHECK_WRKREF_SKIP+=	libexec/git-core/*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/git-cinnabar ${DESTDIR}${PREFIX}/libexec/git-core
	cd ${DESTDIR}${PREFIX}/libexec/git-core && ${LN} git-cinnabar git-remote-hg
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/git-cinnabar

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
