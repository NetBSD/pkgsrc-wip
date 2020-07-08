# $NetBSD$

DISTNAME=	plan9port-20200622
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=9fans/}
GITHUB_TAG=	95ab1308b410ad8547e38e47ec4a36f560dcece5

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://9fans.github.io/plan9port/
COMMENT=	Plan 9 from User Space
LICENSE=	lucent

USE_LANGUAGES=	c c++
USE_TOOLS+=	bash:run perl

REPLACE_BASH+=	bin/macedit
REPLACE_BASH+=	bin/wintext
REPLACE_BASH+=	mac/9term.app/Contents/MacOS/9term
REPLACE_BASH+=	mac/Plumb.app/Contents/MacOS/plumb
REPLACE_BASH+=	src/cmd/rc/checkparse

REPLACE_PERL+=	dist/addsrclinks
REPLACE_PERL+=	dist/fixurls
REPLACE_PERL+=	unix/man/fixurls

REPLACE_INTERPRETER+=	rc
REPLACE.rc.old=		.*/bin/rc
REPLACE.rc.new=		${PREFIX}/plan9/bin/rc
REPLACE_FILES.rc+=	acid/transcript
REPLACE_FILES.rc+=	acid/window
REPLACE_FILES.rc+=	src/cmd/9660/mk9660.rc
REPLACE_FILES.rc+=	src/cmd/dict/egfix
REPLACE_FILES.rc+=	src/cmd/dict/egfix2
REPLACE_FILES.rc+=	src/cmd/dict/gefix
REPLACE_FILES.rc+=	src/cmd/dict/getneeds
REPLACE_FILES.rc+=	src/cmd/fossil/conf.rc
REPLACE_FILES.rc+=	src/cmd/lp/lp.rc
REPLACE_FILES.rc+=	src/cmd/lp/lpsend.rc
REPLACE_FILES.rc+=	src/cmd/map/map.rc
REPLACE_FILES.rc+=	src/cmd/map/mapdemo.rc
REPLACE_FILES.rc+=	src/cmd/netfiles/netfileget
REPLACE_FILES.rc+=	src/cmd/netfiles/netfileput
REPLACE_FILES.rc+=	src/cmd/netfiles/netfilestat
REPLACE_FILES.rc+=	src/cmd/spell/spell.rc
REPLACE_FILES.rc+=	src/cmd/upas/filterkit/pipefrom.sample
REPLACE_FILES.rc+=	src/cmd/upas/misc/mail.rc
REPLACE_FILES.rc+=	src/cmd/upas/misc/qmail
REPLACE_FILES.rc+=	src/cmd/upas/misc/remotemail
REPLACE_FILES.rc+=	src/cmd/venti/srv/conf.rc
REPLACE_FILES.rc+=	src/cmd/venti/srv/tester

pre-build:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/plan9
	${MV} ${WRKSRC}/* ${DESTDIR}${PREFIX}/plan9

do-configure:
	echo "CFLAGS='${CFLAGS}'" >> ${WRKSRC}/LOCAL.config
	echo "LDFLAGS='${LDFLAGS}'" >> ${WRKSRC}/LOCAL.config
	echo "FONTSRV=fontsrv" >> ${WRKSRC}/LOCAL.config

do-build:
	${RUN} cd ${DESTDIR}${PREFIX}/plan9 && \
	    ./INSTALL -b

post-build:
	${RUN} ${FIND} ${DESTDIR}${PREFIX}/plan9 -type f -name '*.orig' | \
	    ${XARGS} ${RM} -f

do-install:
	${RUN} cd ${DESTDIR}${PREFIX}/plan9 && \
	    ./INSTALL -c -r ${PREFIX}/plan9

.include "../../fonts/fontconfig/buildlink3.mk"
PTHREAD_AUTO_VARS=	yes
.include "../../mk/pthread.buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
