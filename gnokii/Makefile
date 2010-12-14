# $NetBSD: Makefile,v 1.10 2010/12/14 16:43:44 noud4 Exp $
#

DISTNAME=		gnokii-0.6.22
CATEGORIES=		comms
MASTER_SITES=		http://www.gnokii.org/download/gnokii/ \
			http://www.gnokii.org/download/gnokii/0.6.x/ \
			http://freesoftware.fsf.org/download/gnokii/ \
			ftp://ftp.gnokii.org/pub/gnokii/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnokii.org/
COMMENT=		Open source tools for your mobile phone

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	common/gnokii.pc.in
USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes
USE_TOOLS+=		autoconf autoheader gmake msgfmt xgettext
USE_BUILTIN.gettext=	no

REPLACE_BASH+=		utils/sendsms
USE_TOOLS+=		bash:run

PKG_DESTDIR_SUPPORT=	user-destdir

pre-configure:
	set -e; cd ${WRKSRC}; autoheader; autoconf

post-install:
	cd ${WRKSRC} && ${MAKE_PROGRAM} ${MAKE_FLAGS} install-devel

.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
