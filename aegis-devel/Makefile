# $NetBSD: Makefile,v 1.3 2013/04/21 18:04:04 kristerw Exp $
#

DISTNAME=	aegis-devel-4.24
CATEGORIES=	meta-pkgs devel
MASTER_SITES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aegis.sourceforge.net/
COMMENT=	Infrastructure meta-package to develop on Aegis

META_PACKAGE=		yes

.include "../../mk/bsd.prefs.mk"

DEPENDS+=		aegis>=4.24:../../devel/aegis
DEPENDS+=		autoconf>=2.53:../../devel/autoconf
DEPENDS+=		automake>=1.10.1:../../devel/automake
DEPENDS+=		bison>=2.4.1:../../devel/bison
DEPENDS+=		cook>=2.8:../../devel/cook
DEPENDS+=		coreutils>=6.12:../../sysutils/coreutils
DEPENDS+=		exctags>=5.7:../../devel/exctags
DEPENDS+=		fhist>=1.16:../../devel/fhist
DEPENDS+=		flex>=2.5.35:../../devel/flex
DEPENDS+=		gawk>=3.1.6:../../lang/gawk
.if ${OPSYS} != "NetBSD"
# on NetBSD gettext is in the base set. others?
DEPENDS+=		gettext>=0.14.4:../../devel/gettext
.endif
DEPENDS+=		ghostscript-agpl>=8.64:../../print/ghostscript-agpl
DEPENDS+=		gsharutils>=4.2.1:../../archivers/gsharutils
DEPENDS+=		ImageMagick>=6.4.8.3:../../graphics/ImageMagick
DEPENDS+=		libxml2>=1.8.17:../../textproc/libxml2
DEPENDS+=		png2ico>=20021208:../../wip/png2ico
DEPENDS+=		pngcrush>=1.6.17:../../graphics/pngcrush
DEPENDS+=		psutils>=1.17:../../print/psutils
.if ${OPSYS} != "NetBSD"
# on NetBSD rcs is in the base set. others?
DEPENDS+=		rcs>=5.7:../../devel/rcs
.endif
DEPENDS+=		rx>=1.5:../../devel/rx
DEPENDS+=		sudo>=1.7.0:../../security/sudo
DEPENDS+=		tardy>=1.17:../../wip/tardy
.if ${OPSYS} != "NetBSD"
# on NetBSD zlib is in the base set. others?
DEPENDS+=		zlib>=1.1.4:../../devel/zlib
.endif

.include "../../mk/bsd.pkg.mk"
