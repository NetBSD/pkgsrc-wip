# $NetBSD: Makefile,v 1.3 2010/06/28 11:07:17 ryo-on Exp $
#

DISTNAME=	ciwiki-1.6.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ciwiki/}

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://ciwiki.sourceforge.net/
COMMENT=	CiWiki is a small and simple WikiWikiWeb implementation written in C

LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/ciwiki-1.6.0 # 1.6.1 archive is broken.

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}
SCRIPTSDIR=	${PREFIX}/share/${PKGBASE}

INSTALLATION_DIRS=	bin \
			${DOCSDIR} \
			${DOCSDIR}/docs \
			${SCRIPTSDIR}/scripts \
			${PKGMANDIR}/man1

DOCFILES=	AUTHORS \
		COPYING \
		ChangeLog \
		INSTALL \
		NEWS \
		README \
		didiwiki-16.png \
		didiwiki.html \
		didiwiki.png \
		styles.css

NEWDOCFILES=	BUGS \
		CIWIKI_ON_USBDRIVE \
		FAQ_HELP \
		FIRST \
		FLASH_PLAYER \
		FORMS \
		HOWTOLOGIN \
		MAILINGCODE \
		MYSERVER \
		PAGESTYLES \
		README

SCRIPTFILES=	activity.sh \
		backup_wiki.sh \
		inet_adr.sh \
		install_files.sh \
		notifynewuser.sh

MANFILES1=	didiwiki.1

CONFFILES=	didiwiki.conf

GNU_CONFIGURE=	yes

post-install:
.for filename in ${DOCFILES} ${CONFFILES}
	${INSTALL_DATA} ${WRKSRC}/${filename} ${DESTDIR}${DOCSDIR}
.endfor
.for filename in ${NEWDOCFILES}
	${INSTALL_DATA} ${WRKSRC}/docs/${filename} ${DESTDIR}${DOCSDIR}/docs
.endfor
	${INSTALL_MAN} ${WRKSRC}/${MANFILES1} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
.for filename in ${SCRIPTFILES}
	${INSTALL_DATA} ${WRKSRC}/scripts/${filename} ${DESTDIR}/${SCRIPTSDIR}/scripts
.endfor

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
