# $NetBSD$

DISTNAME=	openmeters-1.17.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=httpsworldview/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE # or use pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/httpsworldview/openmeters/
COMMENT=	TODO: Short description of the package
LICENSE=	gnu-gpl-v3

# This package depends on a fork of the khronos-egl crate because it was not
# updated for ~3 years. This fork is not yet available as a crate but only as
# a git repository. This is the latest commit of the git repository at the time
# of writing this.
KHRONOS-EGL_REV=	c8687d85ed8475dd1e37974d38f0051aaa1e84cf
DISTFILES=		${DEFAULT_DISTFILES}
DISTFILES+=		khronos-egl-${KHRONOS-EGL_REV}.tar.gz
SITES.khronos-egl-${KHRONOS-EGL_REV}.tar.gz+= -${MASTER_SITE_GITHUB:=httpsworldview/}khronos-egl/archive/${KHRONOS-EGL_REV}.tar.gz


WRKSRC=	${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c

.include "cargo-depends.mk"

.include "../../wip/pipewire/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
