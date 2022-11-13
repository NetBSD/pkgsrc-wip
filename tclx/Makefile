# $NetBSD$

DISTNAME=	tclx-8.4.4
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=flightaware/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/flightaware/tclx/
COMMENT=	Extension to Tcl
LICENSE=	2-clause-bsd

GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "x86_64" || !empty$(MACHINE_ARCH:Maarch64)
CONFIGURE_ARGS+= --enable-64bit
.elif !empty$(MACHINE_ARCH:Mspark64)
CONFIGURE_ARGS+= --enable-64bit-vis
.endif

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
