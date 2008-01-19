# $NetBSD: license-extract.mk,v 1.1 2008/01/19 09:49:27 tnn2 Exp $

post-extract:
	@${CHMOD} -R u+w ${WRKSRC}
	@cp ${PKGSRCDIR}/wip/jdk15/files/x_x2zip.c ${WRKSRC}
	@cd ${WRKSRC} && ${CC} -o x_x2zip x_x2zip.c
	@echo ""
	@echo "=> You will now be shown two licenses. If you accept the terms"
	@echo "=> of each license agreement, type "yes" followed by ENTER to"
	@echo "=> continue. Press ENTER now to continue or CTRL-C at any time"
	@echo "=> to abort."
	@sh -c 'read ANS'
	cd ${WRKSRC} && unzip ${JRL_BINFILE} LICENSE
	more ${WRKSRC}/LICENSE
	@sh -c 'echo -n "=> Do you accept the terms of the license agreement? "; read ANS; if [ "$$ANS" != "yes" ]; then exit 1; fi'
	rm -f ${WRKSRC}/LICENSE
	cd ${WRKSRC} && unzip ${JRL_SRCFILE} LICENSE
	more ${WRKSRC}/LICENSE
	@sh -c 'echo -n "=> Do you accept the terms of the license agreement? "; read ANS; if [ "$$ANS" != "yes" ]; then exit 1; fi'
	cd ${WRKSRC} && unzip ${JRL_BINFILE} X_X && ./x_x2zip 'YES I ACCEPT THE CLICK THROUGH LICENSE.  '  X_X && unzip X_X.zip
	rm -f ${WRKSRC}/X_X
	cd ${WRKSRC} && unzip ${JRL_SRCFILE} X_X && ./x_x2zip 'YES I ACCEPT THE CLICK THROUGH LICENSE.  '  X_X && unzip X_X.zip
