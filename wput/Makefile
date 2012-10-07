# $NetBSD: Makefile,v 1.11 2012/10/07 20:11:07 asau Exp $
#

DISTNAME=	wput-0.6.2
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wput/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wput.sourceforge.net/
COMMENT=	Wput is a command-line ftp-client that looks like wget
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

MAKE_JOBS_SAFE=		no

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGLOCALEDIR}/locale/da
INSTALLATION_DIRS+=	${PKGLOCALEDIR}/locale/de ${PKGLOCALEDIR}/locale/el
INSTALLATION_DIRS+=	${PKGLOCALEDIR}/locale/es ${PKGLOCALEDIR}/locale/fi
INSTALLATION_DIRS+=	${PKGLOCALEDIR}/locale/fr ${PKGLOCALEDIR}/locale/it
INSTALLATION_DIRS+=	${PKGLOCALEDIR}/locale/nl ${PKGLOCALEDIR}/locale/pl
INSTALLATION_DIRS+=	${PKGLOCALEDIR}/locale/ru ${PKGLOCALEDIR}/locale/sv
INSTALLATION_DIRS+=	${PKGLOCALEDIR}/locale/tr ${PKGLOCALEDIR}/locale/zh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wput ${DESTDIR}${PREFIX}/bin/wput
	${LN} -s ${DESTDIR}${PREFIX}/bin/wput ${DESTDIR}${PREFIX}/bin/wdel
	${INSTALL_MAN} ${WRKSRC}/doc/wput.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/wput.1
	${INSTALL_MAN} ${WRKSRC}/doc/wdel.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/wdel.1
	${INSTALL_DATA} ${WRKSRC}/po/da.po \
		${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale/da/wput_da.po
	${INSTALL_DATA} ${WRKSRC}/po/de.po \
		${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale/de/wput_de.po
	${INSTALL_DATA} ${WRKSRC}/po/el.po \
		${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale/el/wput_el.po
	${INSTALL_DATA} ${WRKSRC}/po/es.po \
		${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale/es/wput_es.po
	${INSTALL_DATA} ${WRKSRC}/po/fi.po \
		${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale/fi/wput_fi.po
	${INSTALL_DATA} ${WRKSRC}/po/fr.po \
		${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale/fr/wput_fr.po
	${INSTALL_DATA} ${WRKSRC}/po/it.po \
		${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale/it/wput_it.po
	${INSTALL_DATA} ${WRKSRC}/po/nl.po \
		${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale/nl/wput_nl.po
	${INSTALL_DATA} ${WRKSRC}/po/pl.po \
		${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale/pl/wput_pl.po
	${INSTALL_DATA} ${WRKSRC}/po/ru.po \
		${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale/ru/wput_ru.po
	${INSTALL_DATA} ${WRKSRC}/po/sv.po \
		${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale/sv/wput_sv.po
	${INSTALL_DATA} ${WRKSRC}/po/tr.po \
		${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale/tr/wput_tr.po
	${INSTALL_DATA} ${WRKSRC}/po/zh.po \
		${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale/zh/wput_zh.po

.include "../../mk/bsd.pkg.mk"
