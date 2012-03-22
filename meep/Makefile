# $NetBSD: Makefile,v 1.1.1.1 2012/03/22 21:07:44 outpaddling Exp $
#

DISTNAME=	meep-1.1.1
CATEGORIES=	math
MASTER_SITES=	http://ab-initio.mit.edu/meep/

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://ab-initio.mit.edu/meep/
COMMENT=	FDTD simulation software to model electromagnetic systems
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++ fortran

CONFIGURE_ARGS+=	--with-libctl=${PREFIX}/share/libctl

DEPENDS+=	bash:../../shells/bash

#post-extract:
#	(cd ${WRKSRC} && /usr/pkg/bin/autoconf)

.include "../../jb-wip/harminv/buildlink3.mk"
.include "../../jb-wip/libctl/buildlink3.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
