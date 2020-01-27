# $NetBSD: Makefile,v 1.12 2013/02/28 11:24:15 othyro Exp $
#

DISTNAME=		gnokii-0.6.31
CATEGORIES=		comms
MASTER_SITES=		http://www.gnokii.org/download/gnokii/
MASTER_SITES+=		http://www.gnokii.org/download/gnokii/0.6.x/
MASTER_SITES+=		http://freesoftware.fsf.org/download/gnokii/
MASTER_SITES+=		ftp://ftp.gnokii.org/pub/gnokii/
MASTER_SITES+=		ftp://ftp.slackware.pl/pub/gnokii/gnokii/
MASTER_SITES+=		ftp://ftp.slackware.pl/pub/gnokii/gnokii/0.6.x/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnokii.org/
COMMENT=		Open source tools for your mobile phone
LICENSE=		gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	common/gnokii.pc.in
USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes
USE_TOOLS+=		autoconf autoheader autoreconf flex gmake intltool
USE_TOOLS+=		msgfmt msgmerge perl pkg-config xgettext
USE_BUILTIN.gettext=	no

REPLACE_BASH+=		utils/sendsms
USE_TOOLS+=		bash:run

.include "options.mk"

CONFIGURE_ARGS+=	--enable-security

pre-configure:
	set -e; cd ${WRKSRC}; autoheader; autoconf

post-install:
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xgnokii.1x \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xgnokii.1

.include "../../converters/libiconv/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
