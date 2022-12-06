T=table(out.step_response.time, out.step_response.signals.values(1,:)')
writetable(T, 'stepResponse.xls')