# $NetBSD$

DISTNAME=	ltsmin-v3.0.2-source
PKGNAME=	${DISTNAME:S,-v,-,:S,-source$,,}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=utwente-fmt/ltsmin/releases/download/v3.0.2/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ltsmin.utwente.nl/
COMMENT=	The LTSmin model checking toolset
LICENSE=	modified-bsd

WRKSRC=				${WRKDIR}/ltsmin-3.0.2
GNU_CONFIGURE=			yes
USE_LANGUAGES=			c c++
DEPENDS+=			flex>=2.6.4:../../devel/flex
DEPENDS+=			bison>=3.8.2:../../devel/bison
USE_TOOLS+=			gmake bison
BUILDLINK_TRANSFORM.NetBSD+=	rm:-ldl
CONFIGURE_ARGS+=		PKG_CONFIG=${PREFIX}/bin/pkg-config
CONFIGURE_ARGS+=		--docdir=${PREFIX}/share/doc/${PKGBASE}

post-install:
	DESTDIR=${DESTDIR} gmake -C ${WRKSRC}/doc install-man

# Please install wip/buddy till the time pkgsrc maintainers fix devel/buddy to
# pick the right package from github. The issue is reported on mailing list.
#
# This build does not use sylvan, libczmq and libspot as these aren't available
# in pkgsrc at the time of creating this package.

.include "../../wip/sylvan/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../wip/buddy/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
