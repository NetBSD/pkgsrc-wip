# $NetBSD: Makefile,v 1.1.1.1 2009/01/24 13:58:18 obache Exp $
#

DISTNAME=	xvmware
PKGNAME=	${DISTNAME}-0.0beta${DIST_DATE}
CATEGORIES=	x11 sysutils
MASTER_SITES=	http://www.hi-matic.org/distfiles/citrus/NetBSD/
DIST_SUBDIR=	${PKGBASE}-${DIST_DATE}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.hi-matic.org/diary/?20090124#24-1
COMMENT=	VMware support tools for clipboard and seamless mouse movement

PKG_DESTDIR_SUPPORT=	user-destdir

DIST_DATE=	20081221

USE_IMAKE=	yes

IS_GNU_ICONV.gnu=	YES
IS_GNU_ICONV.native=	NO
SCRIPTS_ENV+=	UseGnuLibiconv=${IS_GNU_ICONV.${ICONV_TYPE}
SCRIPTS_ENV+=	UseGnuLibiconv=YES
SCRIPTS_ENV+=	GnuLibiconvDir=${BUILDLINK_PREFIX.libiconv}
SUBST_CLASSES+=		iconv
SUBST_STAGE.iconv=	pre-configure
SUBST_FILES.iconv=	Imakefile
SUBST_SED.iconv=	-e 's;\(\#define UseGnuLibiconv \).*;\1${IS_GNU_ICONV.${ICONV_TYPE}};'

.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
