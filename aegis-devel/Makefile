# $NetBSD: Makefile,v 1.1 2009/06/09 17:32:49 marko_schuetz Exp $
#

DISTNAME=	aegis-devel-4.24
CATEGORIES=	meta-pkgs devel
MASTER_SITES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aegis.sourceforge.net/
COMMENT=	Infrastructure meta-package to develop on Aegis

META_PACKAGE=   	yes

.include "../../mk/bsd.prefs.mk"

DEPENDS+=		aegis>=4.24:../../devel/aegis
DEPENDS+=		autoconf>=2.53:../../devel/autoconf
DEPENDS+=		automake:../../devel/automake
DEPENDS+=		bison:../../devel/bison
DEPENDS+=		cook>=2.8:../../devel/cook
DEPENDS+=		coreutils:../../sysutils/coreutils
DEPENDS+=		exctags:../../devel/exctags
DEPENDS+=		fhist:../../devel/fhist
DEPENDS+=		flex:../../devel/flex
DEPENDS+=		gawk:../../lang/gawk
DEPENDS+=		gettext>=0.14.4:../../devel/gettext
DEPENDS+=		ghostscript:../../print/ghostscript
DEPENDS+=		gsharutils:../../archivers/gsharutils
DEPENDS+=		ImageMagick:../../graphics/ImageMagick
DEPENDS+=		libxml2>=1.8.17:../../textproc/libxml2
DEPENDS+=		png2ico:../../wip/png2ico
DEPENDS+=		pngcrush:../../graphics/pngcrush
DEPENDS+=		psutils:../../print/psutils
.if ${OPSYS} != "NetBSD"
# on NetBSD rcs is in the base set. others?
DEPENDS+=		rcs>=5.7:../../devel/rcs
.endif
DEPENDS+= 		rx:../../devel/rx
DEPENDS+=		sudo:../../security/sudo
DEPENDS+=		tardy:../../wip/tardy
.if ${OPSYS} != "NetBSD"
# on NetBSD zlib is in the base set. others?
DEPENDS+=		zlib:../../devel/zlib
.endif

.include "../../mk/bsd.pkg.mk"
