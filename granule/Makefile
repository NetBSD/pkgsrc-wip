# $NetBSD: Makefile,v 1.7 2007/01/21 13:38:43 bartoszkuzma Exp $
#

DISTNAME=		granule-1.2.4-1
PKGNAME=		${DISTNAME:S/-1$//}
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=granule/}

MAINTAINER=		bartosz@atom.eu.org
HOMEPAGE=		http://granule.sourceforge.net/
COMMENT=		Program for Leitner methodology for learning new words

BUILD_DEPENDS+=		p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser

USE_DIRS+=		xdg-1.1
USE_LANGUAGES=		c c++ fortran
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		aclocal autoconf autoheader automake
USE_TOOLS+=		intltool msgfmt perl pkg-config xgettext

GNU_CONFIGURE=		yes

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

pre-configure:
	cd ${WRKSRC}; aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/libassa/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
