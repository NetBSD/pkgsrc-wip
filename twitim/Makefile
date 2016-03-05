# $NetBSD: Makefile,v 1.5 2012/10/07 17:17:53 asau Exp $
#

DISTNAME=	twitim_1.5
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://twitim.googlecode.com/files/

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://code.google.com/p/twitim/
COMMENT=	Twitim is a Twitter client for GNOME
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/twitim
USE_LANGUAGES=	# none

REPLACE_PERL=	${WRKSRC}/twitim ${WRKSRC}/ctwitim ${WRKSRC}/Twitim/HyperText.pm

NO_BUILD=	YES

INSTALLATION_DIRS=	share/applications \
			${PKGMANDIR}/man1 \
			etc \
			bin \
			${PERL5_INSTALLVENDORLIB} \
			share/pixmaps/${PKGBASE}

DEPENDS+=	p5-AnyEvent-[0-9]*:../../devel/p5-AnyEvent
DEPENDS+=	p5-glib2-[0-9]*:../../devel/p5-glib2
DEPENDS+=	p5-gtk2-[0-9]*:../../x11/p5-gtk2
DEPENDS+=	p5-LWP-UserAgent-Determined-[0-9]*:../../www/p5-LWP-UserAgent-Determined
DEPENDS+=	p5-JSON-XS-[0-9]*:../../converters/p5-JSON-XS
DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-Net-OAuth-[0-9]*:../../net/p5-Net-OAuth
DEPENDS+=	p5-Data-Random-[0-9]*:../../devel/p5-Data-Random
DEPENDS+=	libgnome-[0-9]*:../../devel/libgnome

.include "options.mk"

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	etc/twitim.conf twitim
SUBST_SED.prefix=	-e 's,/usr,${PREFIX},g'
SUBST_SED.prefix+=	-e 's,/etc/twitim/twitim.conf,${PREFIX}/etc/twitim.conf,g'

PLIST_SUBST+=		PERL5_INSTALLVENDORLIB=${PERL5_INSTALLVENDORLIB:S|${PREFIX}/||:Q}

do-install:
	${INSTALL_DATA} ${WRKSRC}/etc/twitim.desktop ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/etc/twitim-tsocks.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/etc/twitim.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/etc/twitim.conf ${DESTDIR}${PREFIX}/etc
	${INSTALL_SCRIPT} ${WRKSRC}/ctwitim ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/twitim ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/twitim-tsocks ${DESTDIR}${PREFIX}/bin
	chmod 644 ${WRKSRC}/Twitim/*pm
	chmod 644 ${WRKSRC}/Twitim/API/*pm
	${CP} -r ${WRKSRC}/Twitim ${DESTDIR}${PERL5_INSTALLVENDORLIB}
	${INSTALL_DATA} ${WRKSRC}/pixmaps/* ${DESTDIR}${PREFIX}/share/pixmaps/${PKGBASE}

.include "../../lang/perl5/module.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
