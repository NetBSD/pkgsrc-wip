	# Create compiler driver scripts in ${WRKDIR}.
	(cd ${WRKDIR}/.gcc/bin && \
	for _target_ in cc cpp gcc gccbug gcov gnat gnatbind \
		gnatbl gnatchop gnatclean gnatfind gnatkr \
		gnatlink gnatls gnatmake gnatname gnatprep \
		gnatxref gpr2make gprcmd ; do \
		${ECHO} '#!${TOOLS_SHELL}' > $${_target_} && \
		${ECHO} -n "exec ${LOCALBASE}/gccAda-3.4.0/bin/$${_target_}" >> $${_target_} && \
		${ECHO} ' "$$@"' >> $${_target_} && \
		${CHMOD} +x $${_target_}; \
	done )
